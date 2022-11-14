#include "click.h"

click::click()
{
    this->mx = basic::mx;
    this->my = basic::my;
    this->n = basic::n;
}

void click::get_coordinate(int n, int *array_mine, bool *array_seen)
{
    MOUSEMSG mouse2;
    displays display2;
    mouse2 = GetMouseMsg();
    mx = static_cast<int>((mouse2.x - stx) / basic::square);
    my = static_cast<int>((mouse2.y - sty) / basic::square);
    std::cout << mouse2.x << " " << mouse2.y << " " << mx << " " << my << " ";
    if (mx >= 0 && mx < n && my >= 0 && my < n)
    {
        basic::mx = mx;
        basic::my = my;
        std::cout << " 1";
        display2.display_mouse_arrive(array_seen, n);
    }
    std::cout << std::endl;
}

void click::block_num(int *arr, bool *arrb, int i, int j)
{

    displays display4;

    if (*(arr + (i - 1) * n + j - 1) == 0 && i != 0 && j != 0)
    {
        block_num(arr, arrb, i - 1, j - 1);
        *(arrb + (i - 1) * n + j - 1) = 1;
        display4.display_click_blank(j, i);
    }
    else if (*(arr + (i - 1) * n + j - 1) > 0 && i != 0 && j != 0)
    {
        *(arrb + (i - 1) * n + j - 1) = 1;
        display4.display_click_num(j, i, arr);
    }

    if (*(arr + (i - 1) * n + j) == 0 && i != 0)
    {
        block_num(arr, arrb, i - 1, j);
        *(arrb + (i - 1) * n + j) = 1;
        display4.display_click_blank(j, i);
    }
    else if (*(arr + (i - 1) * n + j) > 0 && i != 0)
    {
        *(arrb + (i - 1) * n + j) = 1;
        display4.display_click_num(j, i, arr);
    }

    if (*(arr + (i - 1) * n + j + 1) == 0 && i != 0 && j != n - 1)
    {
        block_num(arr, arrb, i - 1, j + 1);
        *(arrb + (i - 1) * n + j + 1) = 1;
        display4.display_click_blank(j, i);
    }
    else if (*(arr + (i - 1) * n + j + 1) > 0 && i != 0 && j != n - 1)
    {
        *(arrb + (i - 1) * n + j + 1) = 1;
        display4.display_click_num(j, i, arr);
    }

    if (*(arr + i * n + j - 1) == 0 && j != 0)
    {
        block_num(arr, arrb, i, j - 1);
        *(arrb + i * n + j - 1) = 1;
        display4.display_click_blank(j, i);
    }
    else if (*(arr + i * n + j - 1) > 0 && j != 0)
    {
        *(arrb + i * n + j - 1) = 1;
        display4.display_click_num(j, i, arr);
    }

    if (*(arr + i * n + j + 1) == 0 && j != n - 1)
    {
        block_num(arr, arrb, i, j + 1);
        *(arrb + i * n + j + 1) = 1;
        display4.display_click_blank(j, i);
    }
    else if (*(arr + i * n + j + 1) > 0 && j != n - 1)
    {
        *(arrb + i * n + j + 1) = 1;
        display4.display_click_num(j, i, arr);
    }

    if (*(arr + (i + 1) * n + j - 1) == 0 && i != n - 1 && j != 0)
    {
        block_num(arr, arrb, i + 1, j - 1);
        *(arrb + (i + 1) * n + j - 1) = 1;
        display4.display_click_blank(j, i);
    }
    else if (*(arr + (i + 1) * n + j - 1) > 0 && i != n - 1 && j != 0)
    {
        *(arrb + (i + 1) * n + j - 1) = 1;
        display4.display_click_num(j, i, arr);
    }

    if (*(arr + (i + 1) * n + j) == 0 && i != n - 1)
    {
        block_num(arr, arrb, i + 1, j);
        *(arrb + (i + 1) * n + j) = 1;
        display4.display_click_blank(j, i);
    }
    else if (*(arr + (i + 1) * n + j) > 0 && i != n - 1)
    {
        *(arrb + (i + 1) * n + j) = 1;
        display4.display_click_num(j, i, arr);
    }

    if (*(arr + (i + 1) * n + j + 1) == 0 && i != n - 1 && j != n - 1)
    {
        block_num(arr, arrb, i + 1, j + 1);
        *(arrb + (i + 1) * n + j + 1) = 1;
        display4.display_click_blank(j, i);
    }
    else if (*(arr + (i + 1) * n + j + 1) == 0 && i != n - 1 && j != n - 1)
    {
        *(arrb + (i + 1) * n + j + 1) = 1;
        display4.display_click_num(j, i, arr);
    }
}

// void whether_count(int *arr, int i, int j, int n, int &sum)
// {

// }

void click::whether_click(int *array_mine, bool *array_seen)
{
    this->mx = basic::mx;
    this->my = basic::my;
    int i = my;
    int j = mx;

    MOUSEMSG mouse3;
    displays display3;
    mouse3 = GetMouseMsg();
    if (mouse3.uMsg == WM_LBUTTONDOWN)
    {
        if (*(array_mine + my * n + mx) > 8)
        {
            
        }
        else if (*(array_seen + my * n + mx) == 0)
        {
            block_num(array_mine, array_seen, i, j);
        }
    }

    else if (mouse3.uMsg == WM_RBUTTONDOWN)
    {
        
    }

    else
    {

    }
}
