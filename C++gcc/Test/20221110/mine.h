#include <iostream>
// #include <graphics.h>
// #include <conio.h>
// #include <stdio.h>
#include <windows.h>
#include <time.h>

class minesweeper
{
public:
    int create_array_mines(int);
    void random_array(int, int *);
    int create_array_seen();
    void find_around_mines(int *, int);

private:
    int n;
};