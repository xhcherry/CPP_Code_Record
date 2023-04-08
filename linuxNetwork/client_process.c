#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main() {
    // 创建套接字
    int fileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (fileDescriptor == -1) {
        perror("socket");
        exit(-1);
    }
    // 连接服务器端
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    inet_pton(AF_INET, "172.17.8.105", &serverAddr.sin_addr.s_addr);
    serverAddr.sin_port = htons(39999);
    int ret = connect(fileDescriptor, (struct sockaddr*)&serverAddr,
                      sizeof(serverAddr));
    if (ret == -1) {
        perror("connect");
        exit(-1);
    }
    // 通信
    int num = 0;
    while (1) {
        char receiveBuffer[1024] = {0};
        // sprintf(receiveBuffer, "data : %d\n", i++);
        fgets(receiveBuffer, sizeof(receiveBuffer), stdin);
        // 给服务端发送数据
        write(fileDescriptor, receiveBuffer, strlen(receiveBuffer) + 1);

        int len = read(fileDescriptor, receiveBuffer, sizeof(receiveBuffer));
        if (len == -1) {
            perror("read");
            exit(-1);
        } else if (len > 0) {
            printf("receive server data : %s\n", receiveBuffer);
        } else if (len == 0) {
            // 表示服务器端断开连接
            printf("server closed...");
            break;
        }
        usleep(1000);
    }
    close(fileDescriptor);
    return 0;
}