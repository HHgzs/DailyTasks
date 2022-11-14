#include "mine.h"

int minesweeper::create_array_mines(int n)
{
    int *array_mine = new int(n * n);
    for (int i = 0; i < n * n; i++)
    {
        array_mine[i] = 0;
    }
    return *array_mine;
}

void minesweeper::random_array(int n, int *array_mine)
{
    int num = 0;
    if (n = 8)
        num = 10;
    else if (n = 16)
        num = 40;
    else if (n = 24)
        num = 99;
    int *array_x = new int(num);
    int *array_y = new int(num);
    for (int i = 0; i < num; i++)
    {
        srand(time(0));
        array_x[i] = rand() % n;
        srand(time(0));
        array_y[i] = rand() % n;
    }
    for (int i = 0; i < num; i++)
    {
        *(array_mine + (array_x[i]) * n + (array_y[i])) = 9;
    }
}

int minesweeper::create_array_seen()
{
    return 0;
}
void minesweeper::find_around_mines(int *, int)
{
}