#include "basic.h"
#include "display.h"
#include "basic.cpp"
#include "display.cpp"
#include "click.cpp"

int main()
{
    int length0 = 432;
    int square0, d0, a0;
    //int *array_mine;
    int array_mine[576];
    bool array_seen[576];
    displays display1;
    display1.display_start();

    int n = 0;
    n = display1.get_mode();
    
    minesweeper mine1;
    mine1.create_array_mines(array_mine,n);
    mine1.random_array(n, array_mine);
    mine1.find_around_mines(array_mine, n);

    cleardevice();

    square0 = static_cast<int>(length0 / n);
    d0 = static_cast<int>(square0 / 18);
    a0 = static_cast<int>((square0 * 8) / 9);
    display1.display_playground(n, d0, square0, length0);
    mine1.count_mines(n, array_mine);
    mine1.create_array_seen(array_seen,n);
    click click1;
    while(1)
    {
        click1.get_coordinate(n,square0,length0,d0,array_mine,array_seen);
        click1.whether_click();
    }

    system("pause");
}