#include"window.h"
#include<string.h>

chat_window::chat_window()
{
    header = NULL;
    output = NULL;
    friends_list = NULL;
    input = NULL;
}

void chat_window::init()
{
    pthread_mutex_init(&lock,NULL);
    initscr();
}

void chat_window::clear_win_line(WINDOW* _win,int begin,int num)
{
    while(num-- > 0){
        wmove(_win,begin++,0);
        wclrtoeol(_win);
    }
}

WINDOW* chat_window::creat_win(const int &hei,const int &wth,const int &y,const int &x)
{
    WINDOW* _win = newwin(hei,wth,y,x);
    return _win;
}

void chat_window::win_refresh(WINDOW* _win)
{
    box(_win,0,0);
    pthread_mutex_lock(&lock);
    wrefresh(_win);
    pthread_mutex_unlock(&lock);
}

void chat_window::draw_handler()
{
    int hei = LINES/5;
    int wth = COLS;
    int y = 0;
    int x = 0;
    
    this->header = creat_win(hei,wth,y,x);
}

void chat_window::draw_output()
{
    int hei = LINES*3/5;
    int wth = COLS*3/4;
    int y = LINES/5;
    int x = 0;

    this->output = creat_win(hei,wth,y,x);
}

void chat_window::draw_friends_list()
{
    int hei = LINES*3/5;
    int wth = COLS/4;
    int y = LINES/5;
    int x = COLS*3/4;

    this->friends_list = creat_win(hei,wth,y,x); 
}

void chat_window::draw_input()
{ 
    int hei = LINES/5;
    int wth = COLS;
    int y = LINES*4/5;
    int x = 0;

    this->friends_list = creat_win(hei,wth,y,x); 
}


void chat_window::put_str_to_win(WINDOW* _win,int y,int x,const string & _str)
{
    mvaddstr(_win,y,x,_str.c_str());   
}

void chat_window::get_str_from_win(WINDOW* _win,int begin,int num)
{
    char buf[G_BLOCK_SIZE];
    memset(buf,'\0',sizeof(buf));

    wgetnstr(_win,buf,sizeof(buf));
    _out = buf;
}

chat_window::~chat_window()
{
    pthread_mutex_destory(&lock);
    delwin(this->header);
    delwin(this->output);
    delwin(this->friends_list);
    delwin(this->input);
    endwin();
}
