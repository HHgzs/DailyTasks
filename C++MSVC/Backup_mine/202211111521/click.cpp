#include "click.h"

click::click(int m_x = basic::mx, int m_y = basic::my)
{
    mx = m_x;
    my = m_y;
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

void click::block_num(int *array_mine, bool *array_seen)
{
    






}

void click::whether_click(int *array_mine, bool *array_seen)
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
