#include "click.h"

void click::get_coordinate(int n,int square, int *array_mine)
{
    MOUSEMSG mouse;
    mouse = GetMouseMsg();
    int mx = (mouse.x - stx) / square;
    int my = (mouse.y - sty) / square;
    if (mx >= 0 && mx < n && my >= 0 && my < n)
    {
        
    }
}