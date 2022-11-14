#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include "basic.h"
#ifndef _DISPLAY_H
#define _DISPLAY_H

class displays
{
public:
    displays();
    void display_start();
    int get_mode();
    inline void display_playground(int);
    void display_boom(int, int, int);
    void display_flag(int, int, int);
    void display_mouse_arrive(bool *, int);
    void display_click_blank(int, int);
    void display_click_num(int, int,int*);
    void display_click_right();
    void display_win();
    void display_lost();

private:
    int d0, a0;
    int square;
    int length;
    int n;
};
#endif