#include "basic.h"

int *minesweeper::create_array_mines(int n)
{
    int *array_mine = new int(n * n);
    for (int i = 0; i < n * n; i++)
    {
        array_mine[i] = 0;
    }
    return array_mine;
}

inline void minesweeper::random_array(int n, int *array_mine)
{
    int num = 0;
    // std::cout << "&&&" << n << "&&&" << num << std::endl;
    if (n == 8)
    {
        num = 10;
        // std::cout << "?!" << std::endl;
    }
    else if (n == 16)
    {
        num = 40;
        // std::cout << "?!!" << std::endl;
    }
    else if (n == 24)
    {
        num = 99;
        // std::cout << "?!!!" << std::endl;
    }

    int *array_xy = new int(2 * num);
    // std::cout << num << std::endl;

    srand(time(0));
    int num2 = 2 * num;

    for (int i = 0; i < (2 * num); i++)
    {
        array_xy[i] = rand() % n;
        //std::cout << array_xy[i] << " ";
    }

    for (int i = 0; i < num; i++)
    {
        *(array_mine + array_xy[i] * n + array_xy[num + i]) = 9;
    }
}

void minesweeper::test_array(int n, int *array_mine)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << *(array_mine + i * n + j) << " ";
        }
        std::cout << std::endl;
    }
}

int minesweeper::count_mines(int n, int *array_mine)
{
    int sum = 0;
    for (int i = 0; i < n * n; i++)
    {
        if (*(array_mine + i) == 9)
            sum++;
    }
    return sum;
}

bool *minesweeper::create_array_seen(int n)
{
    bool *array_seen = new bool(n * n);
    for (int i = 0; i < n * n; i++)
    {
        array_seen[i] = 0;
    }
    return array_seen;
}

void whether_count(int *arr, int i, int j, int n, int &sum)
{
    if (*(arr + (i - 1) * n + j - 1) == 9 && i != 0 && j != 0)
    {
        sum++;
    }
    if (*(arr + (i - 1) * n + j) == 9 && i != 0)
    {
        sum++;
    }
    if (*(arr + (i - 1) * n + j + 1) == 9 && i != 0 && j != n - 1)
    {
        sum++;
    }
    if (*(arr + i * n + j - 1) == 9 && j != 0)
    {
        sum++;
    }
    if (*(arr + i * n + j + 1) == 9 && j != n - 1)
    {
        sum++;
    }
    if (*(arr + (i + 1) * n + j - 1) == 9 && i != n - 1 && j != 0)
    {
        sum++;
    }
    if (*(arr + (i + 1) * n + j) == 9 && i != n - 1)
    {
        sum++;
    }
    if (*(arr + (i + 1) * n + j + 1) == 9 && i != n - 1 && j != n - 1)
    {
        sum++;
    }
}

void minesweeper::find_around_mines(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (*(arr + i * n + j) != 9)
            {
                int sum = 0;
                whether_count(arr, i, j, n, sum);
                *(arr + i * n + j) = sum;
            }
        }
    }
}