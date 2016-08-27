#include"udp_server.h"
#define G_BLOCK_SIZE 1024

static void print_log(std::string log)
{
    std::cerr<<log<<std::endl;
}

udp_server::udp_server(unsigned short _port)
                        :port(_port)
{
    sock = -1;
}

bool udp_server::register_user(struct sockaddr_in &client)
{
    std::string ip_key = inet_ntoa(client.sin_addr);
    print_log(ip_key);
    std::map<std::string,struct sockaddr_in>::iterator iter = online_user.find(ip_key);
    if(iter != online_user.end() )
    {
        return false;
    }
    online_user.insert(std::pair<std::string,struct sockaddr_in>(ip_key,client));
    return true;
}

udp_server::~udp_server()
{
    if(sock != -1){
        close(sock);
    }
}

int udp_server::init_server()
{
    sock = socket(AF_INET,SOCK_DGRAM,0);
    if(sock < 0){
        print_log(strerror(errno));
        exit(1);
    }
    struct sockaddr_in local;
    local.sin_family =AF_INET;
    local.sin_port =htons(port);
    local.sin_addr.s_addr =htonl(INADDR_ANY);

    if(bind(sock, (struct sockaddr*)&local,sizeof(local))<0)
    {
        print_log(strerror(errno));
        exit(1);    
    }
    return 0;
}

int udp_server::reliable_recv_msg()
{
    std::string out_msg;
    int ret = recv_msg(out_msg);
    if(ret > 0){
        print_log(out_msg);
    }
    return ret;
}

int udp_server::recv_msg(std::string &_out_msg)
{
    char buf[G_BLOCK_SIZE];
    memset(buf,'\0',sizeof(buf));

    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    bzero(&client,len);
    ssize_t size = recvfrom(this->sock,buf,sizeof(buf),0,(struct sockaddr*)&client,&len);
    if(size == -1){
        print_log("recv_msg failed!");
        return 1;
    }else if(size >= 0){
        std::string log = "recv_msg succeed!";
        _out_msg = buf;
        register_user(client);
    }
    return size;
}

int udp_server::send_msg(const std::string &_in_msg,\
                        const struct sockaddr_in &client,\
                        socklen_t len)
{
    ssize_t size = sendto(sock,_in_msg.c_str(),_in_msg.size(),0,(struct sockaddr*)&client,len);
    if(size < 0){
        print_log(strerror(errno));
        return 1;
    }else{
    }

    return 0;
}

int udp_server::reliable_send_msg(const std::string &_in_msg,\
                                 const struct sockaddr_in &client,\
                                socklen_t len)
{
    return send_msg(_in_msg,client,len);
}

int udp_server::broadcast_msg()
{
    std::string msg;
    std::map<std::string,struct sockaddr_in>::iterator iter = online_user.begin();
    for(;iter != online_user.end();++iter){
        reliable_send_msg(msg,iter->second,sizeof(iter->second));
    }
}
