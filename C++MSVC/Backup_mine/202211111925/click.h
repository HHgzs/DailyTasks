#ifndef _CLICK_H
#define _CLICK_H
#include "display.h"

class click
{
public:
    click();
    void get_coordinate(int, int *, bool *);
    void block_num(int *, bool *,int,int);
    void whether_click(int *, bool *);
private:
    int mx;
    int my;
    int n;

};

#endif