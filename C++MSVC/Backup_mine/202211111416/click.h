#ifndef _CLICK_H
#define _CLICK_H
#include "display.h"

class click
{
public:
    void get_coordinate(int, int, int, int, int *, bool *);
    void block_num(int*,bool*);
    void whether_click();
private:
    static int mx;
    static int my;


};

#endif