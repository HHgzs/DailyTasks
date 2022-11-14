#include "basic.h"
#undef UNICODE

displays::displays()
{
    this->d0 = basic::d0;
    this->square = basic::square;
    this->length = basic::length;
    this->a0 = basic::a0;
    this->n = basic::n;
    this->mx = basic::mx;
    this->my = basic::my;
}

void displays::display_start()
{
    // EW_SHOWCONSOLE
    initgraph(540, 720);
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

void displays::display_flag(int mx, int my)
{
    this->square = basic::square;

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
    this->d0 = basic::d0;
    this->square = basic::square;
    this->n = basic::n;

    setfillcolor(RGB(224, 217, 178));
    solidrectangle(stx + mx * square,
                   sty + my * square,
                   stx + (mx + 1) * square,
                   sty + (my + 1) * square);
    setfillcolor(RGB(243, 244, 180));
    solidrectangle(stx + mx * square + d0,
                   sty + my * square + d0,
                   stx + (mx + 1) * square - d0,
                   sty + (my + 1) * square - d0);

    POINT point1[3] = {{static_cast<LONG>(stx + (mx + 0.5) * square),
                        static_cast<LONG>(sty + (my + 0.15) * square)},
                       {static_cast<LONG>(stx + (mx + 0.2) * square),
                        static_cast<LONG>(sty + (my + 0.675) * square)},
                       {static_cast<LONG>(stx + (mx + 0.8) * square),
                        static_cast<LONG>(sty + (my + 0.675) * square)}};
    POINT point2[3] = {{static_cast<LONG>(stx + (mx + 0.5) * square),
                        static_cast<LONG>(sty + (my + 0.875) * square)},
                       {static_cast<LONG>(stx + (mx + 0.2) * square),
                        static_cast<LONG>(sty + (my + 0.355) * square)},
                       {static_cast<LONG>(stx + (mx + 0.85) * square),
                        static_cast<LONG>(sty + (my + 0.355) * square)}};

    setfillcolor(RGB(255, 0, 0));
    solidpolygon(point1, 3);

    setfillcolor(RGB(255, 92, 92));
    solidpolygon(point2, 3);

    setfillcolor(RGB(255, 163, 163));
    solidcircle(static_cast<int>(stx + (mx + 0.5) * square),
                static_cast<int>(sty + (my + 0.5) * square),
                static_cast<int>(0.27 * square));
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

    int square0 = length / 8;
    int y_flag = 135;

    POINT point3[3] = {{static_cast<LONG>(stx + 0.3 * square0),
                        static_cast<LONG>(y_flag + 0.25 * square0)},
                       {static_cast<LONG>(stx + 0.3 * square0),
                        static_cast<LONG>(y_flag + 0.75 * square0)},
                       {static_cast<LONG>(stx + 0.8 * square0),
                        static_cast<LONG>(y_flag + 0.5 * square0)}};

    setfillcolor(RGB(255, 166, 166));
    solidpolygon(point3, 3);
    setfillcolor(RGB(115, 115, 115));
    solidrectangle(stx + 0.28 * square0,
                   y_flag + 0.25 * square0,
                   stx + 0.3 * square0,
                   y_flag + 0.95 * square0);
}

void displays::display_remaining()
{
    // std::string num_str = std::to_string(basic::flags);
    // strcpy_s(num,num_str.c_str());

    // char num[2];
    // sprintf_s(num, "%d", basic::flags);

    setfillcolor(RGB(197, 239, 233));
    solidrectangle(100, 140, 200, 200);
    settextcolor(WHITE);
    settextstyle(75, 0, _T("思源黑体 CN Heavy"));

    if (basic::flags > 9)
    {
        outtextxy(110, 125, static_cast<char>(basic::flags / 10 + 48));
        outtextxy(140, 125, static_cast<char>(basic::flags % 10 + 48));
    }
    else if (basic::flags >= 0)
    {
        outtextxy(110, 125, static_cast<char>(basic::flags + 48));
    }
    else
    {
        outtextxy(110, 125, _T("0"));
    }
}

void displays::display_mouse_arrive(bool *array_seen, int n)
{
    this->mx = basic::mx;
    this->my = basic::my;

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

void displays::display_fill_back(int x, int y)
{
    setfillcolor(RGB(226, 255, 188));
    solidrectangle((stx + x * basic::square + basic::d0),
                   (sty + y * basic::square + basic::d0),
                   (stx + (x + 1) * basic::square - basic::d0),
                   (sty + (y + 1) * basic::square - basic::d0));
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

        settextcolor(RGB(146, 196, 255));
        outtextxy(stx + x * square + 6 * d0, sty + y * square + 1.5 * d0, _T("1"));
        break;

    case 2:

        settextcolor(RGB(157, 167, 255));
        outtextxy(stx + x * square + 6 * d0, sty + y * square + 1.5 * d0, _T("2"));
        break;

    case 3:

        settextcolor(RGB(229, 155, 255));
        outtextxy(stx + x * square + 6 * d0, sty + y * square + 1.5 * d0, _T("3"));
        break;

    case 4:

        settextcolor(RGB(253, 155, 255));
        outtextxy(stx + x * square + 6 * d0, sty + y * square + 1.5 * d0, _T("4"));
        break;

    case 5:

        settextcolor(RGB(255, 133, 192));
        outtextxy(stx + x * square + 6 * d0, sty + y * square + 1.5 * d0, _T("5"));
        break;

    case 6:

        settextcolor(RGB(255, 143, 143));
        outtextxy(stx + x * square + 6 * d0, sty + y * square + 1.5 * d0, _T("6"));
        break;

    case 7:

        settextcolor(RGB(255, 104, 104));
        outtextxy(stx + x * square + 6 * d0, sty + y * square + 1.5 * d0, _T("7"));
        break;

    case 8:

        settextcolor(RGB(255, 255, 255));
        outtextxy(stx + x * square + 6 * d0, sty + y * square + 1.5 * d0, _T("8"));
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
    settextcolor(RGB(255, 156, 156));
    settextstyle(50, 0, _T("甜甜圈海报字体"));
    outtextxy(65, 185, _T("Congratulations"));
}

void displays::display_lost()
{
    settextcolor(RGB(255, 156, 156));
    settextstyle(50, 0, _T("甜甜圈海报字体"));
    outtextxy(130, 185, _T("What a pity"));
}

void displays::display_again()
{
    setfillcolor(RGB(151, 199, 255));
    solidroundrect(155, 510, 395, 590, 30, 30);
    setfillcolor(RGB(196, 223, 255));
    solidroundrect(150, 500, 390, 580, 30, 30);
    settextcolor(RGB(145, 160, 241));
    settextstyle(80, 0, _T("Product Sans Black"));
    outtextxy(190, 498, _T("again"));
}

void displays::display_again_line()
{
    setlinecolor(WHITE);
    setlinestyle(PS_DASH, 5);
    roundrect(153, 503, 387, 577, 30, 30);
}

void displays::display_again_reline()
{
    setlinecolor(RGB(196, 223, 255));
    setlinestyle(PS_DASH, 5);
    roundrect(153, 503, 387, 577, 30, 30);
}