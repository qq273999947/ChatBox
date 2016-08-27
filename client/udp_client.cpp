#include "udp_client.h"
#define G_BLOCK_SIZE 1024

udp_client::udp_client(std::string _remote_ip ,unsigned short _port)
    :remote_ip(_remote_ip)
    ,remote_port(_port)
    ,sock(-1)
    {}
int udp_client::init_client()
{
    sock = socket(AF_INET,SOCK_DGRAM,0);
    if(sock < 0){
        exit(0);                  
    }
    return 0;
}
int udp_client::reliable_recv_msg(std::string &_out_msg)
{
    char buf[G_BLOCK_SIZE];
    memset(buf,'\0',sizeof(buf));
    struct sockaddr_in remote;
    socklen_t len=sizeof(remote);
    ssize_t _size = recvfrom(sock,buf,sizeof(buf),0,(struct sockaddr*)&remote,&len);

    if(_size<0)
    {
      _out_msg = "";
      return 1;         
    }
    else if(_size = 0)
    {
      _out_msg = buf;         
    }
    return 0;
 }

 int udp_client::reliable_send_msg(std::string &_in_msg)
 {
     struct sockaddr_in remote;

     remote.sin_family = AF_INET;
     remote.sin_port = htons(remote_port);
     remote.sin_addr.s_addr = inet_addr(remote_ip.c_str());

     ssize_t _size = sendto(sock,_in_msg.c_str(),_in_msg.size(),0,(struct sockaddr*)&remote,sizeof(remote));

     if(_size<0){
        //sendto errno
        return 1;
     }else{}

    return 0;
 }

 udp_client::~udp_client()
 {
    if(sock >0)
    {
      close(sock);
    }
 }
