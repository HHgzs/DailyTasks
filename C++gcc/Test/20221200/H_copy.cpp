#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, m, s[N][N];
int x[N], y[N], b[N], cnt;
int tx, ty, txx, tyy, l, r;
int sum(int i, int j, int xr, int yr)
{ // �������
	return s[xr][yr] - s[xr][j - 1] - s[i - 1][yr] + s[i - 1][j - 1];
}
int find(int t)
{
	return lower_bound(b + 1, b + cnt + 1, t) - b;
}
int main()
{
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
	}

	for (int i = 1; i <= n; i++)
	{
		b[++cnt] = x[i];
		b[++cnt] = y[i];
	}
	sort(b + 1, b + cnt + 1); // b ����������ɢ��
	cnt = unique(b + 1, b + cnt + 1) - (b + 1);

	for (int i = 1; i <= n; i++)
	{
		tx = find(x[i]);
		ty = find(y[i]);
		s[tx][ty]++;
	}

	for (int i = 1; i <= cnt + 1; i++)
	{
		for (int j = 1; j <= cnt + 1; j++)
		{
			s[i][j] += (s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]); // ��һ�¶�λǰ׺��
		}
	}
	while (m--)
	{
		cin >> l >> r;
		l++, r++;
		tx = find(x[l]);
		ty = find(y[l]);
		txx = find(x[r]);
		tyy = find(y[r]);
		if (tx > txx)
			swap(tx, txx);
		if (ty > tyy)
			swap(ty, tyy);
		cout << sum(tx, ty, txx, tyy) << '\n'; // ֱ������𰸼���
	}
	return 0;
}
