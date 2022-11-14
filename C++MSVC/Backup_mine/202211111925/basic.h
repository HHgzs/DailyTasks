#include <iostream>
#include <windows.h>
#ifndef _BASIC_H
#define _BASIC_H
#define stx 54
#define sty 240
// #define length 432

class basic
{
public:
    void create_array_mines(int *, int);
    inline void random_array(int *);
    void test_array(int, int *);
    int count_mines(int, int *);
    void create_array_seen(bool *, int);
    void find_around_mines(int *);

public:
    static int d0, a0;
    static int length;
    static int square;
    static int n;
    static int mx;
    static int my;
};

#endif