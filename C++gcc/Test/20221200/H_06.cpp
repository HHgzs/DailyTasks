// #include <bits/stdc++.h>
// using namespace std;
// const int N = 10010;

// class basic
// {
// public:
// 	void enter();
// 	int sum_ans(int, int, int, int);
// 	int find(int t);
// 	void get_cofind();
// 	void count_all();
// 	void display();

// private:
// 	int s[N][N], x[N], y[N];
// 	int x11, y11, x22, y22, c1, c2;

// public:
// 	int n, m, nn, b[N];
// };

// void basic::enter()
// {
// 	for (int i = 1; i <= n; i++)
// 	{
// 		cin >> x[i] >> y[i];
// 		b[++nn] = x[i];
// 		b[++nn] = y[i];
// 	}
// }
// int basic::sum_ans(int x01, int y01, int x02, int y02)
// {
// 	return s[x02][y02] - s[x02][y01 - 1] - s[x01 - 1][y02] + s[x01 - 1][y01 - 1];
// }
// int basic::find(int t)
// {
// 	return lower_bound(b + 1, b + nn + 1, t) - b;
// }
// void basic::get_cofind()
// {
// 	for (int i = 1; i <= n; i++)
// 	{
// 		x11 = lower_bound(b + 1, b + nn + 1, x[i]) - b;
// 		y11 = lower_bound(b + 1, b + nn + 1, y[i]) - b;
// 		s[x11][y11]++;
// 	}
// }
// void basic::count_all()
// {
// 	for (int i = 1; i <= nn + 1; i++)
// 	{
// 		for (int j = 1; j <= nn + 1; j++)
// 		{
// 			s[i][j] += (s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]);
// 		}
// 	}
// }
// void basic::display()
// {
// 	while (m--)
// 	{
// 		cin >> c1 >> c2;
// 		c1++, c2++;
// 		x11 = find(x[c1]);
// 		y11 = find(y[c1]);
// 		x22 = find(x[c2]);
// 		y22 = find(y[c2]);
// 		if (x11 > x22)
// 			swap(x11, x22);
// 		if (y11 > y22)
// 			swap(y11, y22);
// 		cout << sum_ans(x11, y11, x22, y22) << '\n';
// 	}
// }

// int main()
// {
// 	cin.tie(0)->ios::sync_with_stdio(false);
// 	basic M;
// 	cin >> M.n >> M.m;
// 	M.enter();
// 	sort(M.b + 1, M.b + M.nn + 1);
// 	M.nn = unique(M.b + 1, M.b + M.nn + 1) - (M.b + 1);
// 	M.get_cofind();
// 	M.count_all();
// 	M.display();
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int s[N][N], x[N], y[N], b[N];
int x11, y11, x22, y22, c1, c2;
int n, m, nn;

void enter();
int sum_ans(int, int, int, int);
int find(int t);
void get_cofind();
void count_all();
void display();
void enter()
{
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		b[++nn] = x[i];
		b[++nn] = y[i];
	}
}
int sum_ans(int x01, int y01, int x02, int y02)
{
	return s[x02][y02] - s[x02][y01 - 1] - s[x01 - 1][y02] + s[x01 - 1][y01 - 1];
}
int find(int t)
{
	return lower_bound(b + 1, b + nn + 1, t) - b;
}
void get_cofind()
{
	for (int i = 1; i <= n; i++)
	{
		x11 = lower_bound(b + 1, b + nn + 1, x[i]) - b;
		y11 = lower_bound(b + 1, b + nn + 1, y[i]) - b;
		s[x11][y11]++;
	}
}
void count_all()
{
	for (int i = 1; i <= nn + 1; i++)
	{
		for (int j = 1; j <= nn + 1; j++)
		{
			s[i][j] += (s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]);
		}
	}
}
void display()
{
	while (m--)
	{
		cin >> c1 >> c2;
		c1++, c2++;
		x11 = find(x[c1]);
		y11 = find(y[c1]);
		x22 = find(x[c2]);
		y22 = find(y[c2]);
		if (x11 > x22)
			swap(x11, x22);
		if (y11 > y22)
			swap(y11, y22);
		cout << sum_ans(x11, y11, x22, y22) << '\n';
	}
}

int main()
{
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n >> m;
	enter();
	sort(b + 1, b + nn + 1);
	nn = unique(b + 1, b + nn + 1) - (b + 1);
	get_cofind();
	count_all();
	display();
	return 0;
}