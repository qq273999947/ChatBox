#include"udp_data.h"

udp_data::to_string(std::string &out)
{
    Json::Value val;
    val["nick_name"] = nick_name;
    val["school"] = school;
    val["msg"] = msg;
    val["type"] = type;

    my_json::serialize(val,out);
}
udp_data::to_value(std::string &in)
{
    Json::Value val_out;
    my_json::deserialize(in,val_out);

    nick_name = val_out["nick_name"].asString();
    school = val_out["school"].asString();
    msg = val_out["msg"].asString();
    cmd = val_out["cmd"].asString();
}
