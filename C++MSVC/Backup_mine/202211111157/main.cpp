#include "basic.h"
#include "display.h"
#include "basic.cpp"
#include "display.cpp"
#include "click.cpp"

int main()
{
    int length0 = 432;
    int square0, d0, a0;
    int *array_mine;
    displays display1;
    display1.display_start();

    int n = 0;
    n = display1.get_mode();
    
    minesweeper mine1;
    array_mine = mine1.create_array_mines(n);
    mine1.random_array(n, array_mine);
    mine1.find_around_mines(array_mine, n);

    cleardevice();

    square0 = static_cast<int>(length0 / n);
    d0 = static_cast<int>(square0 / 18);
    a0 = static_cast<int>((square0 * 8) / 9);
    display1.display_playground(n, d0, square0, length0);
    mine1.count_mines(n, array_mine);
    // while(1)
    // {

    // }

    system("pause");
}