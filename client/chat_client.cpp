#include"udp_client.h"
#include"udp_client.cpp"

int main()
{
    udp_client client;
    client.init_client();
    std::string msg;
    std::string out_msg;
    while(1){
        std::cout<<"please enter:";
        fflush(stdout);
        std::cin>>msg;
        client.reliable_send_msg(msg);
        client.reliable_recv_msg(out_msg);
    }
    return 0;
}
