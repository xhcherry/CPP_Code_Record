#include <arpa/inet.h>
#include <iostream>
#include <cstring>
int main()
{
    char buf[] = "192.168.1.4";
    unsigned int num = 0;
    inet_pton(AF_INET, buf, &num);
    unsigned char* p = reinterpret_cast<unsigned char*>(&num);
    std::cout << static_cast<int>(*p) << " " << static_cast<int>(*(p + 1)) << " "
              << static_cast<int>(*(p + 2)) << " " << static_cast<int>(*(p + 3)) << "\n";
}
