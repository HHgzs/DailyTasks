//# include <stdio.h>
//# include <math.h>
//int main(void)
//{
//	//把三个系数保存到计算机中
//
//	int a = 1;
//	int b = 6;
//	int c = 2;
//	
//
//	float delta;
//	float x1;
//	float x2;
//
//	delta = b * b - 4 * a * c;
//	if (delta > 0)
//	{
//		x1 = (-b + sqrt(delta)) / (2 * a);
//		x2 = (-b - sqrt(delta)) / (2 * a);
//		printf("该一元二次方程有两个解，x1 = %f, x2 = %f\n");
//	}
//	else if (delta == 0)
//	{
//		x1 = (-b) / (2 * a);
//		x2 = (-b) / (2 * a);
//		printf("gaifangchengyouyigejie,x1 = %f ,x2 = %f\n", x1, x2);
//	}
//	else
//	{
//		printf("wujie");
//	}
//	return 0;
//}
// 
// 
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	int number = 0;
//	for (int i = 0; i < 30;i++)
//	{
//		cout << number << endl;
//		number += 7;
//	}
//}

#include<iostream>
#include<string>
using namespace std;

void swap(int& data1, int& data2)
{
	int temp = data1;
	data1 = data2;
	data2 = temp;
}

int main()
{

	int number;
	cout << "enter a number between 1 and 6" << endl;
	cin >> number;
	int body[4];
	for (int i = 0; i < 4; i++)
	{
		body[i] = number;
		number++;
	}
	for (int j = 0; j < 4; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			cout << body[j] << body[1] << body[2] << "\t";
			cout << body[j] << body[1] << body[3] << "\t";
			if(k=0)
			swap(body[1], body[2]);
			if(k=1)
			swap(body[1], body[3]);
		}
		swap(body[1], body[2]);
		swap(body[2], body[3]);
		swap(body[j], body[j + 1]);
		cout << "\n";
	}

}
