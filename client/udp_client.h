#pragma once

#include<iostream>
#include<string>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdio.h>
#include "comm.h"

class udp_client
{
    public:
       udp_client(std::string _remote_ip ="127.0.0.1",unsigned short _port=8080);
       int init_client();
       int reliable_recv_msg(std::string &_out_msg);
       int reliable_send_msg(std::string &_in_msg);
      ~udp_client();
    private:
       int sock;
       std::string remote_ip;
       unsigned short remote_port;

};

