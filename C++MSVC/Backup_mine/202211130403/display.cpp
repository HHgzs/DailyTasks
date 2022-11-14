#include "display.h"
#undef UNICODE

displays::displays()
{
    this->d0 = basic::d0;
    this->square = basic::square;
    this->length = basic::length;
    this->a0 = basic::a0;
    this->n = basic::n;
}

void displays::display_start()
{
    initgraph(540, 720, EW_SHOWCONSOLE);
    setbkcolor(RGB(197, 239, 233));
    cleardevice();
    setfillcolor(RGB(217, 217, 217));
    solidroundrect(150, 255, 415, 350, 20, 20);
    solidroundrect(150, 405, 415, 500, 20, 20);
    solidroundrect(150, 555, 415, 650, 20, 20);
    setfillcolor(RGB(181, 210, 255));
    solidroundrect(135, 250, 405, 340, 17, 17);
    solidroundrect(135, 400, 405, 490, 17, 17);
    solidroundrect(135, 550, 405, 640, 17, 17);
    setfillcolor(RGB(255, 255, 255));
    solidrectangle(0, 157, 482, 169);
    settextstyle(110, 0, _T("思源黑体 CN Heavy"));
    setbkmode(TRANSPARENT);
    outtextxy(35, 50, _T("Mode"));
    settextstyle(100, 0, _T("思源黑体 CN Heavy"));
    settextcolor(RGB(255, 254, 220));
    outtextxy(195, 232, _T("easy"));
    outtextxy(195, 542, _T("hard"));
    settextstyle(90, 0, _T("思源黑体 CN Heavy"));
    outtextxy(155, 395, _T("normal"));
}

int displays::get_mode()
{
    int n = 0;
    while (1)
    {
        MOUSEMSG mouse;
        mouse = GetMouseMsg();
        if (mouse.x >= 125 && mouse.x <= 425 && mouse.y >= 240 && mouse.y <= 360)
        {
            setlinecolor(WHITE);
            setlinestyle(PS_DASH, 5);
            rectangle(125, 240, 425, 360);
            if (mouse.uMsg == WM_LBUTTONDOWN)
            {
                n = 8;
                break;
            }
        }
        else if (mouse.x >= 125 && mouse.x <= 425 && mouse.y >= 390 && mouse.y <= 510)
        {
            setlinecolor(WHITE);
            setlinestyle(PS_DASH, 5);
            rectangle(125, 390, 425, 510);
            if (mouse.uMsg == WM_LBUTTONDOWN)
            {
                n = 16;
                break;
            }
        }

        else if (mouse.x >= 125 && mouse.x <= 425 && mouse.y >= 540 && mouse.y <= 660)
        {
            setlinecolor(WHITE);
            setlinestyle(PS_DASH, 5);
            rectangle(125, 540, 425, 660);
            if (mouse.uMsg == WM_LBUTTONDOWN)
            {
                n = 24;
                break;
            }
        }
        else
        {
            setlinecolor(RGB(197, 239, 233));
            setlinestyle(PS_SOLID, 6);
            rectangle(125, 240, 425, 360);
            rectangle(125, 390, 425, 510);
            rectangle(125, 540, 425, 660);
        }
    }
    return n;
}

inline void displays::display_playground(int n)
{
    this->d0 = basic::d0;
    this->square = basic::square;
    this->length = basic::length;
    setfillcolor(RGB(211, 236, 207));
    solidrectangle(stx, sty, stx + length, sty + length);
    setfillcolor(RGB(226, 255, 188));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int left = stx + j * square + d0;
            int top = sty + i * square + d0;
            int right = stx + (j + 1) * square - d0;
            int bottom = sty + (i + 1) * square - d0;
            solidrectangle(left, top, right, bottom);
        }
    }
    setbkmode(TRANSPARENT);
    settextcolor(RGB(255, 248, 188));
    settextstyle(100, 0, _T("思源黑体 CN Heavy"));
    outtextxy(27, 20, _T("Mode"));
    settextcolor(RGB(236, 255, 197));
    settextstyle(75, 0, _T("思源黑体 CN Heavy"));
    if (n == 8)
    {
        outtextxy(240, 40, _T("easy"));
    }
    else if (n == 16)
    {
        outtextxy(240, 40, _T("normal"));
    }
    else if (n == 24)
    {
        outtextxy(240, 40, _T("hard"));
    }
}

void displays::display_flag(int mx, int my)
{
    this->square = basic::square;
    this->n = basic::n;
    POINT point[3] = {{static_cast<LONG>(stx + (mx + 0.3) * square),
                       static_cast<LONG>(sty + (my + 0.25) * square)},
                      {static_cast<LONG>(stx + (mx + 0.3) * square),
                       static_cast<LONG>(sty + (my + 0.75) * square)},
                      {static_cast<LONG>(stx + (mx + 0.8) * square),
                       static_cast<LONG>(sty + (my + 0.5) * square)}};
    setfillcolor(RGB(255, 166, 166));
    solidpolygon(point, 3);
    setfillcolor(RGB(115, 115, 115));
    solidrectangle(stx + (mx + 0.28) * square,
                   sty + (my + 0.25) * square,
                   stx + (mx + 0.3) * square,
                   sty + (my + 0.95) * square);
}

void displays::display_boom(int mx, int my)
{
    this->square = basic::square;
    this->n = basic::n;

    POINT point1[3] = {{static_cast<LONG>(stx + (mx + 0.5) * square),
                        static_cast<LONG>(sty + (my + 0.15) * square)},
                       {static_cast<LONG>(stx + (mx + 0.2) * square),
                        static_cast<LONG>(sty + (my + 0.675) * square)},
                       {static_cast<LONG>(stx + (mx + 0.8) * square),
                        static_cast<LONG>(sty + (my + 0.675) * square)}};
    POINT point2[3] = {{static_cast<LONG>(stx + (mx + 0.5) * square),
                        static_cast<LONG>(sty + (my + 0.85) * square)},
                       {static_cast<LONG>(stx + (mx + 0.2) * square),
                        static_cast<LONG>(sty + (my + 0.355) * square)},
                       {static_cast<LONG>(stx + (mx + 0.8) * square),
                        static_cast<LONG>(sty + (my + 0.355) * square)}};
    setfillcolor(RGB(0, 0, 0));
    solidpolygon(point1, 3);
    solidpolygon(point2, 3);
    solidcircle(static_cast<int>(stx + (mx + 0.5) * square),
                static_cast<int>(sty + (my + 0.5) * square),
                static_cast<int>(0.27 * square));
}

void displays::display_mouse_arrive(bool *array_seen, int n)
{
    int mx = basic::mx;
    int my = basic::my;
    if (*(array_seen + my * n + mx) == 0)
    {
        setlinecolor(RGB(255, 200, 233));
        setlinestyle(PS_DASH, d0);
        rectangle((stx + mx * square + d0 * 2),
                  (sty + my * square + d0 * 2),
                  (stx + (mx + 1) * square - d0 * 2),
                  (sty + (my + 1) * square - d0 * 2));
    }
}

void displays::display_click_blank(int x, int y)
{
    this->d0 = basic::d0;
    this->square = basic::square;
    this->n = basic::n;
    setfillcolor(RGB(186, 217, 181));
    solidrectangle(stx + x * square,
                   sty + y * square,
                   stx + (x + 1) * square,
                   sty + (y + 1) * square);
    setfillcolor(RGB(185, 238, 184));
    solidrectangle(stx + x * square + d0,
                   sty + y * square + d0,
                   stx + (x + 1) * square - d0,
                   sty + (y + 1) * square - d0);
}

void displays::display_click_num(int x, int y, int *arr)
{
    this->d0 = basic::d0;
    this->square = basic::square;
    this->n = basic::n;
    setfillcolor(RGB(186, 217, 181));
    solidrectangle(stx + x * square,
                   sty + y * square,
                   stx + (x + 1) * square,
                   sty + (y + 1) * square);
    setfillcolor(RGB(185, 238, 184));
    solidrectangle(stx + x * square + d0,
                   sty + y * square + d0,
                   stx + (x + 1) * square - d0,
                   sty + (y + 1) * square - d0);
    setbkmode(TRANSPARENT);

    settextstyle(basic::a0, 0, _T("思源黑体 CN Heavy"));

    switch (*(arr + y * n + x))
    {
    case 1:

        settextcolor(RGB(171, 225, 255));
        outtextxy(stx +x*square+ 6 * d0, sty+y*square + 1.5 * d0, _T("1"));
        break;

    case 2:
    
        settextcolor(RGB(140, 200, 255));
        outtextxy(stx +x*square+ 6 * d0, sty+y*square + 1.5 * d0, _T("2"));
        break;
    
    case 3:
    
        settextcolor(RGB(131, 181, 255));
        outtextxy(stx+x*square + 6 * d0, sty+y*square + 1.5 * d0, _T("3"));
        break;
    
    case 4:
    
        settextcolor(RGB(149, 147, 255));
        outtextxy(stx+x*square + 6 * d0, sty+y*square + 1.5 * d0, _T("4"));
        break;
    
    case 5:
    
        settextcolor(RGB(240, 178, 255));
        outtextxy(stx+x*square + 6 * d0, sty+y*square + 1.5 * d0, _T("5"));
        break;
    
    case 6:
    
        settextcolor(RGB(255, 185, 210));
        outtextxy(stx+x*square + 6 * d0, sty+y*square + 1.5 * d0, _T("6"));
        break;
    
    case 7:
    
        settextcolor(RGB(255, 159, 159));
        outtextxy(stx+x*square + 6 * d0, sty+y*square + 1.5 * d0, _T("7"));
        break;
    
    case 8:
    
        settextcolor(RGB(255, 110, 110));
        outtextxy(stx+x*square + 6 * d0, sty+y*square + 1.5 * d0, _T("8"));
        break;
    
    }
    // if (*(arr + y * n + x) == 1)
    // {
    //     settextcolor(RGB(171, 225, 255));
    //     outtextxy(stx + 6 * d0, sty + 1.5 * d0, _T("1"));
    // }
    //
    // if (*(arr + y * n + x) == 2)
    // {
    //     settextcolor(RGB(140, 200, 255));
    //     outtextxy(stx + 6 * d0, sty + 1.5 * d0, _T("2"));
    // }
    //
    // if (*(arr + y * n + x) == 3)
    // {
    //     settextcolor(RGB(131, 181, 255));
    //     outtextxy(stx + 6 * d0, sty + 1.5 * d0, _T("3"));
    // }
    //
    // if (*(arr + y * n + x) == 4)
    // {
    //     settextcolor(RGB(149, 147, 255));
    //     outtextxy(stx + 6 * d0, sty + 1.5 * d0, _T("4"));
    // }
    //
    // if (*(arr + y * n + x) == 5)
    // {
    //     settextcolor(RGB(240, 178, 255));
    //     outtextxy(stx + 6 * d0, sty + 1.5 * d0, _T("5"));
    // }
    //
    // if (*(arr + y * n + x) == 6)
    // {
    //     settextcolor(RGB(255, 185, 210));
    //     outtextxy(stx + 6 * d0, sty + 1.5 * d0, _T("6"));
    // }
    //
    // if (*(arr + y * n + x) == 7)
    // {
    //     settextcolor(RGB(255, 159, 159));
    //     outtextxy(stx + 6 * d0, sty + 1.5 * d0, _T("7"));
    // }
    //
    // if (*(arr + y * n + x) == 8)
    // {
    //     settextcolor(RGB(255, 110, 110));
    //     outtextxy(stx + 6 * d0, sty + 1.5 * d0, _T("8"));
    // }
}

void displays::display_win()
{
}
void displays::display_lost()
{
}