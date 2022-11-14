//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
/*作者的话：
**游戏名称：OC贪吃蛇/OCSnake
**游戏版本：1.0
**游戏规则：WSAD控制光标，空格暂停，ENTER确定，ESC退出
*/
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
#include<iostream>
#include<string>
#include<Windows.h>
#include<ctime>
#include<conio.h>
using namespace std;
#define _SPEED(_LENGTH) _LENGTH>6?_LENGTH:6//蛇的速度
#define _SCORE(_LENGTH) _LENGTH//游戏得分
//贪吃蛇
class Snake {
public:
	//默认构造函数
	Snake() :length(3), direction(6), speed(3), maxRow(10), maxCol(15), initLength(3) {
		map = new signed char*[maxRow];
		int count;
		for (count = 0; count < maxRow; count++) {
			map[count] = new signed char[maxCol];
			memset(map[count], 0, maxCol);
		}
		head[0] = 0; head[1] = 2;
		tail[0] = 0; tail[1] = 0;
		for (count = 0; count < 2; count++)
			map[0][count] = 6;
		map[0][count] = -4;
		system("title OCSnake");
		system(string("mode con cols=" + to_string(2 * maxCol + 4) + " lines=" + to_string(maxRow + 2)).c_str());
		create();
	}
	//构造函数：MRow>=8,MCol>=10
	Snake(int const&MRow, int const&MCol, int const&init_length = 3) :direction(6), maxRow(MRow), maxCol(MCol), initLength(init_length) {
		length = initLength;
		map = new signed char*[maxRow];
		int count;
		for (count = 0; count < maxRow; count++) {
			map[count] = new signed char[maxCol];
			memset(map[count], 0, maxCol);
		}
		head[0] = 0; head[1] = initLength - 1;
		tail[0] = 0; tail[1] = 0;
		for (count = 0; count < initLength - 1; count++)
			map[0][count] = 6;
		map[0][count] = -4;
		system("title OCSnake");
		system(string("mode con cols=" + to_string(2 * maxCol + 4) + " lines=" + to_string(maxRow + 2)).c_str());
		create();
	}
	//游戏开始
	void GameStart() {
		srand((unsigned)time(NULL));
	LABEL_MAIN_WINDOW://主窗口标签
		if (MainWindow())
			if (QuitOrNot())goto LABEL_MAIN_WINDOW;
			else exit(0);
		else if (ChooseMode())goto LABEL_MAIN_WINDOW;
		Sleep(CLOCKS_PER_SEC);
		char pause_before_continue = 0;
		while (true) {
			print();
			if (pause_before_continue) { Sleep(CLOCKS_PER_SEC); pause_before_continue = 0; }
			if (_kbhit())switch (_getch()) {
			case'w':case'W':turn(8); break;
			case's':case'S':turn(2); break;
			case'a':case'A':turn(4); break;
			case'd':case'D':turn(6); break;
			case 27:case 32: LABEL_PAUSE_WINDOW://暂停窗口
				if (0 == pause()) {
					if (0 == ReturnToMainWindow())goto LABEL_MAIN_WINDOW; 
					else goto LABEL_PAUSE_WINDOW;
				}pause_before_continue = 1;
				break;
			}if (move()) { Sleep(CLOCKS_PER_SEC); score(); goto LABEL_MAIN_WINDOW; }
			Sleep(CLOCKS_PER_SEC / speed);
		}
	}
	//析构函数
	~Snake() {
		int count;
		for (count = 0; count < maxCol; count++)
			delete[]map[count];
		delete[]map;
	}
private:
	signed char**map;//地图
	int length;//蛇的长度
	int head[2];//蛇头坐标
	int tail[2];//蛇尾坐标
	char direction;//移动方向：8-↑，2-↓，4-←，6-→
	char speed;//蛇的速度
	const char maxRow;//地图最大行数
	const char maxCol;//地图最大列数
	const char initLength;//初始蛇长
	char mode;//游戏模式：0-正常模式，1-无障碍模式
	//打印
	void print()const {
		int i, j; signed char judge;
		for (i = 0; i < maxCol + 2; i++)cout << "□";
		cout << endl;
		for (i = 0; i < maxRow; i++) {
			cout << "□";
			for (j = 0; j < maxCol; j++) {
				judge = map[i][j];
				if (0 == judge)cout << "  ";
				else if (judge > 0)cout << "■";
				else if (-1 == judge)cout << "◇";
				else cout << "¤";
			}cout << "□" << endl;
		}for (i = 0; i < maxCol + 2; i++)cout << "□";
	}
	//移动：0-正常移动，1-撞墙，2-咬到自己
	int move() {
		int front;
		if (0 == mode) {
			switch (direction) {
			case 8:
				if (head[0]) {
					if ((front = map[head[0] - 1][head[1]]) > 0)return 2;
					map[head[0]--][head[1]] = 8;
					map[head[0]][head[1]] = -2;
					if (front < 0) { create(); length++; }
					else switch (map[tail[0]][tail[1]]) {
					case 8:map[tail[0]--][tail[1]] = 0; break;
					case 2:map[tail[0]++][tail[1]] = 0; break;
					case 4:map[tail[0]][tail[1]--] = 0; break;
					case 6:map[tail[0]][tail[1]++] = 0; break;
					}return 0;
				}
				else return 1;
			case 2:
				if (head[0] < maxRow - 1) {
					if ((front = map[head[0] + 1][head[1]]) > 0)return 2;
					map[head[0]++][head[1]] = 2;
					map[head[0]][head[1]] = -8;
					if (front < 0) { create(); length++; }
					else switch (map[tail[0]][tail[1]]) {
					case 8:map[tail[0]--][tail[1]] = 0; break;
					case 2:map[tail[0]++][tail[1]] = 0; break;
					case 4:map[tail[0]][tail[1]--] = 0; break;
					case 6:map[tail[0]][tail[1]++] = 0; break;
					}return 0;
				}
				else return 1;
			case 4:
				if (head[1]) {
					if ((front = map[head[0]][head[1] - 1]) > 0)return 2;
					map[head[0]][head[1]--] = 4;
					map[head[0]][head[1]] = -6;
					if (front < 0) { create(); length++; }
					else switch (map[tail[0]][tail[1]]) {
					case 8:map[tail[0]--][tail[1]] = 0; break;
					case 2:map[tail[0]++][tail[1]] = 0; break;
					case 4:map[tail[0]][tail[1]--] = 0; break;
					case 6:map[tail[0]][tail[1]++] = 0; break;
					}return 0;
				}
				else return 1;
			case 6:
				if (head[1] < maxCol - 1) {
					if ((front = map[head[0]][head[1] + 1]) > 0) return 2;
					map[head[0]][head[1]++] = 6;
					map[head[0]][head[1]] = -4;
					if (front < 0) { create(); length++; }
					else switch (map[tail[0]][tail[1]]) {
					case 8:map[tail[0]--][tail[1]] = 0; break;
					case 2:map[tail[0]++][tail[1]] = 0; break;
					case 4:map[tail[0]][tail[1]--] = 0; break;
					case 6:map[tail[0]][tail[1]++] = 0; break;
					}return 0;
				}
				else return 1;
			default:return -1;
			}
		}
		else {
			char judge;
			switch (direction) {
			case 8:
				if (head[0]) {
					if ((front = map[head[0] - 1][head[1]]) > 0)return 2;
					map[head[0]--][head[1]] = 8;
					map[head[0]][head[1]] = -2;
				}
				else {
					if ((front = map[maxRow - 1][head[1]]) > 0)return 2;
					map[head[0]][head[1]] = 8; head[0] = maxRow - 1;
					map[head[0]][head[1]] = -2;
				}
					if (front < 0) { create(); length++; }
					else {
						judge = map[tail[0]][tail[1]]; map[tail[0]][tail[1]] = 0;
						switch (judge) {
						case 8: if (tail[0])tail[0]--; else tail[0] = maxRow - 1; break;
						case 2: if (tail[0] < maxRow - 1)tail[0]++; else tail[0] = 0; break;
						case 4: if (tail[1])tail[1]--; else tail[1] = maxCol - 1; break;
						case 6:if (tail[1] < maxCol - 1)tail[1]++; else tail[1] = 0; break;
						}
					}return 0;
			case 2:
				if (head[0] < maxRow - 1) {
					if ((front = map[head[0] + 1][head[1]]) > 0)return 2;
					map[head[0]++][head[1]] = 2;
					map[head[0]][head[1]] = -8;
				}
				else {
					if ((front = map[0][head[1]]) > 0)return 2;
					map[head[0]][head[1]] = 2; head[0] = 0;
					map[head[0]][head[1]] = -8;
				}
				if (front < 0) { create(); length++; }
				else {
					judge = map[tail[0]][tail[1]]; map[tail[0]][tail[1]] = 0;
					switch (judge) {
					case 8: if (tail[0])tail[0]--; else tail[0] = maxRow - 1; break;
					case 2: if (tail[0] < maxRow - 1)tail[0]++; else tail[0] = 0; break;
					case 4: if (tail[1])tail[1]--; else tail[1] = maxCol - 1; break;
					case 6:if (tail[1] < maxCol - 1)tail[1]++; else tail[1] = 0; break;
					}
				}return 0;
			case 4:
				if (head[1]) {
					if ((front = map[head[0]][head[1] - 1]) > 0)return 2;
					map[head[0]][head[1]--] = 4;
					map[head[0]][head[1]] = -6;
				}
				else {
					if ((front = map[head[0]][maxCol - 1]) > 0)return 2;
					map[head[0]][head[1]] = 4; head[1] = maxCol - 1;
					map[head[0]][head[1]] = -6;
				}
				if (front < 0) { create(); length++; }
				else {
					judge = map[tail[0]][tail[1]]; map[tail[0]][tail[1]] = 0;
					switch (judge) {
					case 8: if (tail[0])tail[0]--; else tail[0] = maxRow - 1; break;
					case 2: if (tail[0] < maxRow - 1)tail[0]++; else tail[0] = 0; break;
					case 4: if (tail[1])tail[1]--; else tail[1] = maxCol - 1; break;
					case 6:if (tail[1] < maxCol - 1)tail[1]++; else tail[1] = 0; break;
					}
				}return 0;
			case 6:
				if (head[1] < maxCol - 1) {
					if ((front = map[head[0]][head[1] + 1]) > 0) return 2;
					map[head[0]][head[1]++] = 6;
					map[head[0]][head[1]] = -4;
				}
				else {
					if ((front = map[head[0]][0]) > 0) return 2;
					map[head[0]][head[1]] = 6; head[1] = 0;
					map[head[0]][head[1]] = -4;
				}
				if (front < 0) { create(); length++; }
				else {
					judge = map[tail[0]][tail[1]]; map[tail[0]][tail[1]] = 0;
					switch (judge) {
					case 8: if (tail[0])tail[0]--; else tail[0] = maxRow - 1; break;
					case 2: if (tail[0] < maxRow - 1)tail[0]++; else tail[0] = 0; break;
					case 4: if (tail[1])tail[1]--; else tail[1] = maxCol - 1; break;
					case 6:if (tail[1] < maxCol - 1)tail[1]++; else tail[1] = 0; break;
					}
				}return 0;
			default:return -1;
			}
		}
	}
	//转弯
	void turn(int const&kbinput) {
		switch (kbinput) {
		case 8:if (4 == direction || 6 == direction)direction = 8; break;
		case 2:if (4 == direction || 6 == direction)direction = 2; break;
		case 4:if (8 == direction || 2 == direction)direction = 4; break;
		case 6:if (8 == direction || 2 == direction)direction = 6; break;
		}
	}
	//生成食物
	void create() {
		int position[2];
		do {
			position[0] = rand() % maxRow;
			position[1] = rand() % maxCol;
		} while (map[position[0]][position[1]]);
		map[position[0]][position[1]] = -1;
		speed = _SPEED(length);
	}
	//暂停游戏：0-返回主界面，1-继续游戏
	int pause() {
		int i, j; signed char judge;
		for (i = 0; i < maxCol + 2; i++)cout << "□";
		cout << endl;
		for (i = 0; i < maxRow / 2 - 3; i++) {
			cout << "□";
			for (j = 0; j < maxCol; j++)cout << "  ";
			cout << "□" << endl;
		}
		cout << "□"; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "◣    "; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "□" << endl;
		cout << "□"; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "■◣  "; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "□" << endl;
		cout << "□"; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "■■◣"; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "□" << endl;
		cout << "□"; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "■■◤"; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "□" << endl;
		cout << "□"; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "■◤  "; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "□" << endl;
		cout << "□"; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "◤    "; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "□" << endl;
		for (; i < maxRow - 6; i++) {
			cout << "□";
			for (j = 0; j < maxCol; j++)cout << "  ";
			cout << "□" << endl;
		}
		for (i = 0; i < maxCol + 2; i++)cout << "□";
		judge = _getch();
		while (judge != 27 && judge != 32)judge = _getch();
		return 27 == judge ? 0 : 1;
	}
	//主界面：0-开始，1-退出
	int MainWindow() {
		system("cls");
		char cursor = 0, position = 0;
		do {
			unsigned short i, j;
			for (i = 0; i < maxCol + 2; i++)cout << "■";
			cout << endl;
			for (i = 0; i < maxRow / 2 - 1; i++) {
				cout << "■";
				for (j = 0; j < maxCol; j++)cout << "  ";
				cout << "■" << endl;
			}
			cout << "■"; for (j = 0; j < maxCol - 8; j++)cout << ' '; cout << "OC贪吃蛇/OCSnake"; for (j = 0; j < maxCol - 8; j++)cout << ' '; cout << "■" << endl;
			cout << "■"; for (j = 0; j < maxCol - 4; j++)cout << ' '; cout << "开始游戏"; 
			if (0 == position)cout << "←"; for (j = 2 - 2 * position; j < maxCol - 4; j++)cout << ' '; cout << "■" << endl;
			cout << "■"; for (j = 0; j < maxCol - 4; j++)cout << ' '; cout << "退出游戏";
			if (position)cout << "←";  for (j = 2 * position; j < maxCol - 4; j++)cout << ' '; cout << "■" << endl;
			for (; i < maxRow - 3; i++) {
				cout << "■";
				for (j = 0; j < maxCol; j++)cout << "  ";
				cout << "■" << endl;
			}
			for (i = 0; i < maxCol + 2; i++)cout << "■";
			cursor = _getch();
			if (('w' == cursor || 'W' == cursor) && position)position--;
			else if (('s' == cursor || 'S' == cursor) && 0 == position)position++;
			else if (27 == cursor)return 1;
		} while (cursor != '\r');
		return position;
	}
	//退出确认窗口：0-是，1-否
	int QuitOrNot() {
		char cursor = 0, position = 0;
		do {
			unsigned short i, j;
			for (i = 0; i < maxCol + 2; i++)cout << "■";
			cout << endl;
			for (i = 0; i < maxRow / 2 - 1; i++) {
				cout << "■";
				for (j = 0; j < maxCol; j++)cout << "  ";
				cout << "■" << endl;
			}
			cout << "■"; for (j = 0; j < maxCol - 6; j++)cout << ' '; cout << "要结束游戏吗"; for (j = 0; j < maxCol - 6; j++)cout << ' '; cout << "■" << endl;
			cout << "■"; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "是  否"; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "■" << endl;
			if (0 == position) { cout << "■"; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "↑"; for (j = 0; j < maxCol + 1; j++)cout << ' '; cout << "■" << endl; }
			else { cout << "■"; for (j = 0; j < maxCol + 1; j++)cout << ' '; cout << "↑"; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "■" << endl; }
			for (; i < maxRow - 3; i++) {
				cout << "■";
				for (j = 0; j < maxCol; j++)cout << "  ";
				cout << "■" << endl;
			}for (i = 0; i < maxCol + 2; i++)cout << "■";
			cursor = _getch();
			if (('a' == cursor || 'A' == cursor) && position)position--;
			else if (('d' == cursor || 'D' == cursor) && 0 == position)position++;
			else if (27 == cursor)return 1;
		} while (cursor != '\r');
		return position;
	}
	//返回主菜单：0-是，1-否
	int ReturnToMainWindow() {
		char cursor = 0, position = 0;
		do {
			unsigned short i, j;
			for (i = 0; i < maxCol + 2; i++)cout << "■";
			cout << endl;
			for (i = 0; i < maxRow / 2 - 1; i++) {
				cout << "■";
				for (j = 0; j < maxCol; j++)cout << "  ";
				cout << "■" << endl;
			}
			cout << "■"; for (j = 0; j < maxCol - 7; j++)cout << ' '; cout << "要返回主菜单吗"; for (j = 0; j < maxCol - 7; j++)cout << ' '; cout << "■" << endl;
			cout << "■"; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "是  否"; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "■" << endl;
			if (0 == position) { cout << "■"; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "↑"; for (j = 0; j < maxCol + 1; j++)cout << ' '; cout << "■" << endl; }
			else { cout << "■"; for (j = 0; j < maxCol + 1; j++)cout << ' '; cout << "↑"; for (j = 0; j < maxCol - 3; j++)cout << ' '; cout << "■" << endl; }
			for (; i < maxRow - 3; i++) {
				cout << "■";
				for (j = 0; j < maxCol; j++)cout << "  ";
				cout << "■" << endl;
			}for (i = 0; i < maxCol + 2; i++)cout << "■";
			cursor = _getch();
			if (('a' == cursor || 'A' == cursor) && position)position--;
			else if (('d' == cursor || 'D' == cursor) && 0 == position)position++;
			else if (27 == cursor)return 1;
		} while (cursor != '\r');
		return position;
	}
	//结算界面
	void score() {
		int count; signed char judge;
		system("cls");
		for (count = 0; count < maxCol/2-2; count++)cout << endl;
		for (count = 0; count < maxCol - 2; count++)cout << ' '; cout << "游戏结束" << endl;
		for (count = 0; count < maxCol - 6; count++)cout << ' '; cout << "你的最终得分为：" << _SCORE(length - initLength);
		for (count = 0; count < maxRow; count++) {
			map[count] = new signed char[maxCol];
			memset(map[count], 0, maxCol);
		}
		head[0] = 0; head[1] = initLength - 1;
		tail[0] = 0; tail[1] = 0;
		for (count = 0; count < initLength - 1; count++)
			map[0][count] = 6;
		map[0][count] = -4;
		direction = 6; 
		length = initLength; create();
		judge = _getch();
		while (judge != 27 && judge != '\r')judge = _getch();
	}
	//模式选择窗口：0-开始游戏，1-返回主菜单
	int ChooseMode() {
		char cursor = 0, position = 0;
		do {
			unsigned short i, j;
			for (i = 0; i < maxCol + 2; i++)cout << "■";
			cout << endl;
			for (i = 0; i < maxRow / 2 - 1; i++) {
				cout << "■";
				for (j = 0; j < maxCol; j++)cout << "  ";
				cout << "■" << endl;
			}
			cout << "■"; for (j = 0; j < maxCol - 7; j++)cout << ' '; cout << "请选择游戏模式"; for (j = 0; j < maxCol - 7; j++)cout << ' '; cout << "■" << endl;
			cout << "■"; for (j = 0; j < maxCol - 6; j++)cout << ' '; cout << "正常  无障碍"; for (j = 0; j < maxCol - 6; j++)cout << ' '; cout << "■" << endl;
			if (0 == position) { cout << "■"; for (j = 0; j < maxCol - 5; j++)cout << ' '; cout << "↑"; for (j = 0; j < maxCol + 3; j++)cout << ' '; cout << "■" << endl; }
			else { cout << "■"; for (j = 0; j < maxCol + 2; j++)cout << ' '; cout << "↑"; for (j = 0; j < maxCol - 4; j++)cout << ' '; cout << "■" << endl; }
			for (; i < maxRow - 3; i++) {
				cout << "■";
				for (j = 0; j < maxCol; j++)cout << "  ";
				cout << "■" << endl;
			}for (i = 0; i < maxCol + 2; i++)cout << "■";
			cursor = _getch();
			if (('a' == cursor || 'A' == cursor) && position)position--;
			else if (('d' == cursor || 'D' == cursor) && 0 == position)position++;
			else if (27 == cursor)return 1;
		} while (cursor != '\r');
		mode = position;
		return 0;
	}
};
int main() {
	Snake OCSnake;
	OCSnake.GameStart();
	return 0;
}

