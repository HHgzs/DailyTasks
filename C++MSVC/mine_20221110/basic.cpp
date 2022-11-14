#include "basic.h"

void basic::create_array_mines(int *array_mine, int n)
{
    // int *array_mine = new int(n * n);
    for (int i = 0; i < n * n; i++)
    {
        array_mine[i] = 0;
    }
}

inline void basic::random_array(int *array_mine)
{
    int num = 0;
    if (n == 8)
    {
        num = 10;
    }
    else if (n == 16)
    {
        num = 40;
    }
    else if (n == 24)
    {
        num = 99;
    }

    int array_xy[200];
    srand(time(0));

    for (int i = 0; i < (2 * num); i++)
    {
        array_xy[i] = rand() % n;
    }

    for (int i = 0; i < num; i++)
    {
        *(array_mine + array_xy[i] * n + array_xy[num + i]) = 9;
    }

}

void basic::test_array(int n, int *array_mine)
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

int basic::count_mines(int n, int *array_mine)
{
    int sum0 = 0;
    for (int i = 0; i < n * n; i++)
    {
        if (*(array_mine + i) == 9)
            sum0++;
    }
    return sum0;
}

void basic::create_array_bool(bool *array_bool, int n)
{
    for (int i = 0; i < n * n; i++)
    {
        array_bool[i] = 0;
    }
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

void basic::find_around_mines(int *arr)
{
    for (int i = 0; i < basic::n; i++)
    {
        for (int j = 0; j < basic::n; j++)
        {
            if (*(arr + i * basic::n + j) != 9)
            {
                int sum = 0;
                whether_count(arr, i, j, basic::n, sum);
                *(arr + i * basic::n + j) = sum;
            }
        }
    }
}