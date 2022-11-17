// #include "display.cpp"
#include "basic.cpp"

// void display_start()
// {
//     initgraph(540, 720);
//     setbkcolor(RGB(197, 239, 233));
//     cleardevice();
//     setfillcolor(RGB(217, 217, 217));
//     solidroundrect(150, 255, 415, 350, 20, 20);
//     solidroundrect(150, 405, 415, 500, 20, 20);
//     solidroundrect(150, 555, 415, 650, 20, 20);
//     setfillcolor(RGB(181, 210, 255));
//     solidroundrect(135, 250, 405, 340, 17, 17);
//     solidroundrect(135, 400, 405, 490, 17, 17);
//     solidroundrect(135, 550, 405, 640, 17, 17);
//     setfillcolor(RGB(255, 255, 255));
//     solidrectangle(0, 157, 482, 169);
//     settextstyle(110, 0, _T("思源黑体 CN Heavy"));
//     setbkmode(TRANSPARENT);
//     outtextxy(35, 50, _T("Mode"));
//     settextstyle(100, 0, _T("思源黑体 CN Heavy"));
//     settextcolor(RGB(255, 254, 220));
//     outtextxy(195, 232, _T("easy"));
//     outtextxy(195, 542, _T("hard"));
//     settextstyle(90, 0, _T("思源黑体 CN Heavy"));
//     outtextxy(155, 395, _T("normal"));
// }

// void get_mode(int &n)
// {
//     while (1)
//     {
//         MOUSEMSG mouse;
//         mouse = GetMouseMsg();
//         if (mouse.x >= 135 && mouse.x <= 404 && mouse.y >= 255 && mouse.y <= 346)
//         {
//             setlinecolor(WHITE);
//             setlinestyle(PS_DASH, 5);
//             rectangle(125, 240, 425, 360);
//             if (mouse.uMsg == WM_LBUTTONDOWN)
//             {
//                 n = 8;
//                 break;
//             }
//         }
//         else if (mouse.x >= 135 && mouse.x <= 404 && mouse.y >= 392 && mouse.y <= 484)
//         {
//             setlinecolor(WHITE);
//             setlinestyle(PS_DASH, 5);
//             rectangle(125, 390, 425, 510);
//             if (mouse.uMsg == WM_LBUTTONDOWN)
//             {
//                 n = 16;
//                 break;
//             }
//         }

//         else if (mouse.x >= 135 && mouse.x <= 404 && mouse.y >= 526 && mouse.y <= 621)
//         {
//             setlinecolor(WHITE);
//             setlinestyle(PS_DASH, 5);
//             rectangle(125, 540, 425, 660);
//             if (mouse.uMsg == WM_LBUTTONDOWN)
//             {
//                 n = 24;
//                 break;
//             }
//         }
//         else
//         {
//             setlinecolor(RGB(197, 239, 233));
//             setlinestyle(PS_SOLID, 6);
//             rectangle(125, 240, 425, 360);
//             rectangle(125, 390, 425, 510);
//             rectangle(125, 540, 425, 660);
//         }
//     }
// }

int main()
{

    // display_start();
    int n = 0;
    // get_mode(n);
    // cleardevice();


    std::cin >> n;
    //closegraph();
    std::cout << n;

    minesweeper mine1;
    int* array_mine=0;
    *array_mine = mine1.create_array_mines(n);
    mine1.random_array(n,array_mine);
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << *(array_mine + i*n + j);
        }
        std::cout << std::endl;
    }





    system("pause");
}