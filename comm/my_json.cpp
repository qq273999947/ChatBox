#include"my_json.h"

my_json::my_json()
{}

int my_json::serialize(Json::Value &_in_val, string &_str_out)
{
    #ifdef _STYLE_
        Json::StyleWriter _write;
    #else
        Json::FastWriter _write;
    #endif
        _str_out = _write.write(_in_val);
}

int my_json::deserialize(string& _in_str, Json::Value &_val_out)
{
    Json::Reader _reader;
    if(_reader.parse(_in_str, _val_out, false) > 0)
    {
        return 0;    
    }
    return 1;
}

my_json::~my_json()
{}

#ifdef _DEBUG_

int main()
{
    Json::Value _val;
    string _str_out;
    _val["nick name"] = "coroline";
    _val["school"] = "SUST";
    _val["msg"] = "en...";
    my_json::serialize(_val, _str_out);
    cout << _str_out << endl;

    Json::Value _val_out;
    my_json::deserialize(_str_out, _val_out);

    cout << _val_out["nick name"].asString() << endl;
    cout << _val_out["school"].asString() << endl;
    cout << _val_out["msg"].asString() << endl;
        
    return 0;
}

#endif
