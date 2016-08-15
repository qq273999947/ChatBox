#pragma once

#include<iostream>
#include<string>
#include<map>
#include<errno.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>

class udp_server{
    private:
    int recv_msg(const std::string &_out_msg);
    int send_msg(const std::string &_in_msg,\
                 const struct sockaddr_in& client,socklen_t len);
    bool register_user(struct sockaddr_in &client);

    public:
    udp_server(unsigned short _port = 8080);
    int init_server();
    int reliable_send_msg(const std::string &in_msg,\
                         const struct sockaddr_in &client,\
                         socklen_t len);
    int reliable_recv_msg();
    int broadcast_msg();
    ~udp_server();

    private:
    int sock;
    unsigned short port;
    //data_pool pool;
    std::map<std::string,struct sockaddr_in> online_user;
}
