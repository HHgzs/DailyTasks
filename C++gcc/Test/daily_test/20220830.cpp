#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <stdio.h>
using namespace std;

int main()
{
	string user_name;
	cout << "Please enter your name: \n";
	cin >> user_name;
	cout << '\n';
	cout << "Welcome\t" << user_name << '\n';
	Sleep(1000);
	cout << "Do you want to play a game?\n";
	Sleep(1000);
	char game_start;
	bool start = true;
	while (start == true)
	{
		cout << "Please enter Y/N \n";
		cin >> game_start;
		if ( game_start == 'N' || game_start == 'n')
			start = false;
		else
		if ( game_start == 'Y' || game_start == 'y')
		{
			cout << "Nice!\n";
			break;
		}
		else 
		{
			cout << "Follow my guidance\n";
		}
			
	}

	if (!start)
	{
		Sleep(1000);
		cout << "What a pity!! \n";
		Sleep(1000);
		cout << "\tHow dare you refuse me!!!!\n";
	}

	else 
	{
		Sleep(1000);
		int number;
		cout << "We will produce a number\n";
		Sleep(1000);

		srand((unsigned)time(NULL));
		number = rand();
		number /= 1000;
		
		cout << "This is an integer within one hundred\n";
		Sleep(1000);
		cout << "Guest the integer\n";
		Sleep(1000);
		cout << "We will tell you whether it is big or small\n";
		Sleep(1000);
		cout << "NOW----";
		for (int i = 0; i < 4; i++)
		{
			cout << "-";
			Sleep(200);

		}
		cout << "START\n";

		for (int i = 0; i < 20; i++)
		{
			cout << "■";
			Sleep(300);
		}
		cout << "\n\t开始游戏" << endl;
		cout << number;

		int try_times = 0;
		int user_enter;
		bool continue_game = true;

		while(continue_game = true)
		{
			cout << "Please enter your guess——";
			cin >> user_enter;
			if (user_enter > number)
			{
				cout << "\nAh~~ Too large! Try again please";
				++try_times;
			}
			else
			if (user_enter == number)
			{
				cout << "Nice!!! You win";
				++try_times;
			}
			else
			{
				cout << "\nyooo~~ Too small! Try again please";
				++try_times;
			}

		}

	}

}