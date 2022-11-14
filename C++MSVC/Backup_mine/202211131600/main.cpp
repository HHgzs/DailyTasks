#include "basic.h"
#include "basic.cpp"
#include "display.cpp"
#include "click.cpp"
#pragma comment(linker, "/STACK:10240000000,10240000000")

int basic::mx = 0;
int basic::my = 0;
int basic::n = 0;
int basic::square = 0;
int basic::d0 = 0;
int basic::a0 = 0;
int basic::length = 432;
int basic::sum = 0;
int basic::flags = 0;
int basic::key = 1;

int main()
{
    int array_mine[576];
    bool array_seen[576];
    bool array_flags[576];

    displays display1;
    display1.display_start();

    basic::n = display1.get_mode();

    basic mine1;
    mine1.create_array_mines(array_mine, basic::n);
    mine1.random_array(array_mine);
    mine1.find_around_mines(array_mine);
    basic::sum = mine1.count_mines(basic::n, array_mine);
    basic::flags = basic::sum;

    cleardevice();

    basic::square = static_cast<int>(basic::length / basic::n);
    basic::d0 = static_cast<int>(basic::square / 18);
    basic::a0 = static_cast<int>((basic::square * 8) / 9);

    display1.display_playground(basic::n);
    mine1.count_mines(basic::n, array_mine);
    mine1.create_array_bool(array_seen, basic::n);
    mine1.create_array_bool(array_flags, basic::n);

    // mine1.test_array(basic::n,array_mine);

    click click1;

    while (basic::key = 1)
    {
        click1.get_coordinate(basic::n, array_mine, array_seen, array_flags);
    }

    if (basic::key == -1)
    {
        display1.display_lost();
    }
    
    else if (basic::key == 0)
    {
        display1.display_win();
    }

    system("pause");
}