#pragma once

#include<iostream>
#include<ncurses.h>
#include<string.h>
#include<pthread.h>
#include"comm.h"
using namespace std;

class chat_window
{
    public:
        chat_window();
        ~chat_window();
        void init();
        WINDOW* creat_win(const int &hei,const int &wth,const int &y,const int &x);
        void clear_win_line(WINDOW* _win,int begin,int num);
        void win_refresh(WINDOW* _win);
        void put_str_to_win(WINDOW* _win,int y,int x,const string & _str);
        void get_str_from_win(WINDOW* _win,int begin,int num);
        WINDOW* get_header()
        {
            return this->header;
        }
        WINDOW* get_output()
        {
            return this->output;
        }
        WINDOW* get_friend_list()
        {
            return this->friends_list;
        }
        WINDOW* get_input()
        {
            return this->input;
        }
    private:
        WINDOW* header;
        WINDOW* output;
        WINDOW* friends_list;
        WINDOW* input;
        pthread_mutex_t lock;
}
