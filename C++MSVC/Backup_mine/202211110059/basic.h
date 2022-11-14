#include <iostream>
#include <windows.h>
#ifndef _BASIC_H
#define _BASIC_H

class minesweeper
{
public:
    int *create_array_mines(int);
    inline void random_array(int, int *);
    void test_array(int, int *);
    int count_mines(int,int *);
    bool *create_array_seen(int);
    void find_around_mines(int *, int);

private:
    int n;
};

#endif