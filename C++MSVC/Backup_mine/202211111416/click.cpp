#include "click.h"

void click::get_coordinate(int n, int square, int length, int d0, int *array_mine, bool *array_seen)
{
    MOUSEMSG mouse2;
    displays display2;
    mouse2 = GetMouseMsg();
    int mx = static_cast<int>((mouse2.x - stx) / square);
    int my = static_cast<int>((mouse2.y - sty) / square);
    std::cout << mouse2.x << " " << mouse2.y << " " << mx << " " << my << " ";
    if (mx >= 0 && mx < n && my >= 0 && my < n)
    {
        std::cout << " 1";
        display2.display_mouse_arrive(array_seen, n, mx, my, square, d0);
    }
    std::cout << std::endl;
}

void click::block_num(int *array_mine, bool *array_seen)
{





}

void click::whether_click()
{
    MOUSEMSG mouse3;
    displays display3;
    mouse3 = GetMouseMsg();
    if (mouse3.uMsg == WM_LBUTTONDOWN)
    {



    }

    else if (mouse3.uMsg == WM_RBUTTONDOWN)
    {



    }
    
    else
    {




    }
}
