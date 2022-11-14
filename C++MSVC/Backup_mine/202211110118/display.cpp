#include "display.h"
#undef UNICODE

void displays::display_start()
{
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
