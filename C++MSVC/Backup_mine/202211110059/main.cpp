#include "basic.h"
#include "display.h"
#include "basic.cpp"
#include "display.cpp"

int main()
{
    displays display1;
    display1.display_start();
    int n = 0;
    n = display1.get_mode();
    cleardevice();
    closegraph();
    std::cout << n << std::endl;
    minesweeper mine1;
    int *array_mine = mine1.create_array_mines(n);
    mine1.random_array(n, array_mine);
    mine1.find_around_mines(array_mine,n);

    mine1.test_array(n,array_mine);







    system("pause");
}