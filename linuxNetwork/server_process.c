#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
void recyleChild(int arg) {
    while(1) {
        int ret = waitpid(-1, NULL, WNOHANG);
        if(ret == -1) {
            // 所有的子进程都回收了
            break;
        }else if(ret == 0) {
            // 还有子进程活着
            break;
        } else if(ret > 0){
            // 被回收了
            printf("子进程 %d 被回收了\n", ret);
        }
    }
}
int main()
{
    // struct sigaction act;
    // act.sa_flags = 0;
    // sigemptyset(&act.sa_mask);
    // act.sa_handler = recyleChild;
    // 注册信号捕捉
    //sigaction(SIGCHLD, &act, NULL);
    // 创建socket
    int listenFileDescriptor = socket(PF_INET, SOCK_STREAM, 0);
    if (listenFileDescriptor == -1)
    {
        perror("socket");
        exit(-1);
    }
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9999);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    // 绑定
    int ret = bind(listenFileDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    if (ret == -1)
    {
        perror("bind");
        exit(-1);
    }
    // 监听
    ret = listen(listenFileDescriptor, 128);
    if (ret == -1)
    {
        perror("listen");
        exit(-1);
    }
    // 不断循环等待客户端连接
    while (1)
    {
        struct sockaddr_in clientAddress;
        int len = sizeof(clientAddress);
        // 接受连接
        int connectionFileDescriptor = accept(listenFileDescriptor, (struct sockaddr *)&clientAddress, &len);
        if (connectionFileDescriptor == -1)
        {
            perror("accept");
            exit(-1);
        }
        // 每一个连接进来，创建一个子进程跟客户端通信
        pid_t pid = fork();
        if (pid == 0)
        {
            // 子进程
            // 获取客户端信息
            char clientIp[16];
            inet_ntop(AF_INET, &clientAddress.sin_addr.s_addr, clientIp, sizeof(clientIp));
            unsigned short clientPort = ntohs(clientAddress.sin_port);
            printf("client ip is : %d, port is %d \n", clientPort, clientPort);
            // 接收客户端发来的数据
            char receiveBuffer[1024] = {0}; // 接收数据缓冲区
            while (1)
            {
                int len = read(connectionFileDescriptor, &receiveBuffer, sizeof(receiveBuffer));
                if (len == -1)
                {
                    perror("read");
                    exit(-1);
                }
                else if (len > 0)
                {
                    printf("receive client data : %s \n", receiveBuffer);
                }
                else
                {
                    printf("client closed...");
                }
                write(connectionFileDescriptor, receiveBuffer, strlen(receiveBuffer) + 1);
            }
            close(connectionFileDescriptor);
            exit(0); // 退出当前子进程
        }
    }
    close(listenFileDescriptor);
    return 0;
}