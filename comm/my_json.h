#pragma once
#include <iostream>
#include <string.h>
#include "json/json.h"
using namespace std;

class my_json
{
    public:
        my_json();
        ~my_json();
        static int serialize(Json::Value &_in_val, string &_str_out);
        static int deserialize(string& _in_str, Json::Value &_val_out);
};
