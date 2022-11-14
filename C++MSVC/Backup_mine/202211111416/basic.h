#include <iostream>
#include <windows.h>
#ifndef _BASIC_H
#define _BASIC_H
#define stx 54
#define sty 240
// #define length 432


class minesweeper
{
public:
    void create_array_mines(int* ,int);
    inline void random_array(int, int *);
    void test_array(int, int *);
    int count_mines(int,int *);
    void create_array_seen(bool*,int);
    void find_around_mines(int *, int);

private:
    int n;
};

#endif