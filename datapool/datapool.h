#pragma once

#include<iostream>

class data_pool{
    private:
    std::vector<std::string> pool;
    int capacity;
    public:  
    data_pool();
    get_data();
    put_data();
    ~data_pool();
};
