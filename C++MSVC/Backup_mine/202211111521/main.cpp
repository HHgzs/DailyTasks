#include "basic.h"
#include "display.h"
#include "basic.cpp"
#include "display.cpp"
#include "click.cpp"

int basic::mx = 0;
int basic::my = 0;
int basic::n = 0;
int basic::square = 0;
int basic::d0 = 0;
int basic::a0 = 0;
int basic::length = 432;

int main()
{
    int array_mine[576];
    bool array_seen[576];

    displays display1;
    display1.display_start();

    basic::n = display1.get_mode();

    basic mine1;
    mine1.create_array_mines(array_mine, basic::n);
    mine1.random_array(array_mine);
    mine1.find_around_mines(array_mine);

    cleardevice();

    basic::square = static_cast<int>(basic::length / basic::n);
    basic::d0 = static_cast<int>(basic::square / 18);
    basic::a0 = static_cast<int>((basic::square * 8) / 9);

    display1.display_playground(basic::n);
    mine1.count_mines(basic::n, array_mine);
    mine1.create_array_seen(array_seen, basic::n);

    click click1;
    while (1)
    {
        click1.get_coordinate(basic::n, array_mine, array_seen);
        // click1.whether_click();
    }

    system("pause");
}