#include "basic.h"
#include "display.h"
#include "basic.cpp"
#include "display.cpp"
#include "click.cpp"

int main()
{
    displays display1;
    display1.display_start();

    int n = 0;
    n = display1.get_mode();

    minesweeper mine1;
    int *array_mine = mine1.create_array_mines(n);
    mine1.random_array(n, array_mine);
    mine1.find_around_mines(array_mine, n);

    cleardevice();
    int length0 = 432;
    int square0 = length0 / n;
    int d0 = square0 / 9;
    int a0 = (square0 * 8) / 9;
    display1.display_playground(n,d0,square0,length0);






    system("pause");
}