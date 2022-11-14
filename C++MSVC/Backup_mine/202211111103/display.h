#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include "basic.h"
#ifndef _DISPLAY_H
#define _DISPLAY_H

class displays
{
public:
    void display_start();
    int get_mode();
    inline void display_playground(int,int,int,int);
    void display_click_left();
    void display_find_around();
    void display_click_right();
    void display_win();
    void display_lost();

};
#endif