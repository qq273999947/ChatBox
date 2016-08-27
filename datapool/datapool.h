#pragma once

#ifndef _DATA_POOL_
#define _DATA_POOL_

#include <iostream>
#include <semaphore.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

using namespace std;

#define CAPACITY 1024

class data_pool
{
    public:
        data_pool();
        void get_msg(string &_out_msg);
        void put_msg(const string &_in_msg);
        ~data_pool();
    private:
        sem_t put_sem;
        sem_t get_sem;
        vector<string> pool;
        int size;
        int start;
        int end;

};
#endif
