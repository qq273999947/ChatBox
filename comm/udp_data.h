#pragma once

#include<iostream>
#include"my_json.h"

class udp_data{
    public:
        udp_data(){}
        ~udp_data(){}
        void set_nick_name(const std::string &s)
                        :nick_name(s)
        {}
        void set_school(const std::string &s)
                        :school(s)
        {}
        void set_msg(const std::string &s)
                    :msg(s)
        {}
        void set_type(const std::string &s)
                    :type(s)
        {}      
        void get_nick_name(const std::string &s)
        {
            s = nick_name;
        }
        void set_school(const std::string &s)
        {
            s = school;
        }
        void set_msg(const std::string &s)
        {
            s = msg;
        }
        void set_type(const std::string &s)
        {
            s = type;
        }
        void to_string(std::string &out);
        void to_value(std::string &in);
    public:
        std::string nick_name;
        std::string school;
        std::string msg;
        std::string type;
}
