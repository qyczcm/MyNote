//TCP通信发服务器端


#include <windows.h>
// #include <sys/types.h>
// #include <sys/socket.h>
#include <stdio.h>



int main()
{
    //1.创建socket（用于监听的套接字）
    //AF_INET:ipv4  SOCK_STREAM:流式协议
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if(lfd == -1){
        perror("Creat_Socket");
    }

    //2.绑定
    struct sockaddr_in saddr;
    inet_pton()
    saddr.sin_family = AF_INET;
    saddr.sin_addr.S_addr = 
    bind(lfd,)

    return 0;
}
