#include <iostream>
#include <string>
#include <windows.h>
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#ifndef _BASIC_H
#define _BASIC_H
#define stx 54
#define sty 240

class basic
{
public:
    void create_array_mines(int *, int);
    inline void random_array(int *);
    void test_array(int, int *);
    int count_mines(int, int *);
    void create_array_bool(bool *, int);
    void find_around_mines(int *);

public:
    static int d0, a0;
    static int length;
    static int square;
    static int n;
    static int key;
    static int sum;
    static int flags;
    static int mx;
    static int my;
};

class displays
{
public:
    displays();
    void display_start();
    int get_mode();
    void display_boom(int, int);
    void display_flag(int, int);
    inline void display_playground(int);
    void display_remaining();
    void display_mouse_arrive(bool *, int);
    void display_fill_back(int, int);
    void display_click_blank(int, int);
    void display_click_num(int, int, int *);
    void display_win();
    void display_lost();
    void display_again();
    void display_again_above();
    void display_again_line();
    void display_again_reline();

private:
    int d0, a0;
    int square;
    int length;
    int n;
    int mx, my;
};

class click : public displays
{
public:
    click();
    void get_coordinate(int, int *, bool *,bool *);
    void block_num(int *, bool *, int, int);
    void whether_click_left(int *, bool *);
    void whether_click_right(int *, bool *,bool *);
    void start_again();

private:
    int x0;
    int y0;
    int mx;
    int my;
    int n;
    int mx_last;
    int my_last;
};

#endif