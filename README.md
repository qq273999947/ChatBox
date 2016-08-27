> - udp_server中包含一个类，此类的成员有sock,port,和map类型的online user,类的功能主要是注册聊天用户，初始化聊天室，收发消息，把消息公告再群聊室里，此聊天室基于udp完成，用json库来进行序列化和反序列化。
> - client和server端都可以通过udp接口接受或者发送消息。
