// #undef UNICODE
// #include <graphics.h>
// #include <conio.h>
// #include<stdio.h>
// int main()
// {
// 	MOUSEMSG m;
// 	// 初始化绘图窗口
// 	initgraph(640, 480);
// 	// 设置背景色为白色
// 	setbkcolor(WHITE);
// 	// 用背景色清空屏幕
// 	cleardevice();
// 	setfillcolor(RED);
// 	fillrectangle(100, 100, 300, 150);
// 	settextstyle(15, 0, "微软黑体");
// 	setbkmode(TRANSPARENT);
// 	outtextxy(150, 120, "Hello,World!");
// 	while (1) {
// 		m = GetMouseMsg();
// 		if (m.x >= 100 && m.x <= 300 && m.y >= 100 && m.y <= 150) {
// 			setlinecolor(BLUE);
// 			rectangle(90, 95, 310, 160);
// 			if (m.uMsg == WM_LBUTTONDOWN) {		//如果按下鼠标左键实现相应功能.
// 				closegraph();
// 				printf("HHHHHHHHHHHHHHHH\n");
// 				break;
// 			}
// 		}
// 		else {	//当鼠标不在目标位置就覆盖之前的蓝色边框.
// 			setlinecolor(WHITE);
// 			rectangle(90, 95, 310, 160);
// 		}
// 	}
// 	// 按任意键退出
// 	_getch();
// 	closegraph();//关闭窗口
// }




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
//
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
