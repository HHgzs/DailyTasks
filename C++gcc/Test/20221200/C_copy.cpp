#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
ll read()
{
	ll x = 0, f = 0;
	char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-')
			f = 1;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return f ? -x : x;
}
ll Day[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 365};
bool isrun(ll x)
{
	if (x % 4)
		return 0;
	else
	{
		if (x % 100 == 0)
		{
			if (x % 400 == 0)
				return 1;
			else
				return 0;
		}
		return 1;
	}
}
ll y_to_d(ll x)
{
	ll ans = 0;
	for (ll i = 1000; i < x; i++)
	{
		ans += Day[12] + isrun(i);
	}
	return ans;
}
ll m_to_d(ll run, ll x)
{
	ll ans = 0;
	for (ll i = 0; i < x; i++)
	{
		if (i == 1 && run)
			ans++;
		ans += Day[i];
	}
	return ans;
}
ll d_to_s(ll x, ll y, ll z)
{
	return (x * 60ll + y) * 60 + z;
}
const ll mod = 24 * 60 * 60;
string Mo[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
void weiba(ll x)
{
	if (x == 1 || x == 21 || x == 31)
		cout << "st ";
	else if (x == 2 || x == 22)
		cout << "nd ";
	else if (x == 3 || x == 23)
		cout << "rd ";
	else
		cout << "th ";
	//	cout << "th ";
}
void solve(ll day, ll k)
{
	//	cout << "DDDDDDDDDDDDDDDDD:: " <<day << endl;
	ll year = 1000;
	for (ll i = 1000; day >= Day[12] + isrun(i); i++, year = i)
	{
		day -= Day[12] + isrun(i);
	}
	ll month = 0;
	for (int i = 0; i < 12; i++, month = i)
	{
		if (i == 1 && isrun(year))
		{
			if (day >= Day[i] + 1)
			{
				day -= Day[i] + 1;
			}
			else
				break;
		}
		else if (day >= Day[i])
		{
			day -= Day[i];
		}
		else
			break;
	}
	cout << Mo[month] << " ";
	cout << day + 1;
	weiba(day + 1);
	printf("%02d:%02d:%02d %d\n", (k / 3600), ((k / 60) % 60), (k % 60), year);
}
int main()
{
	int T = read();
	while (T--)
	{
		ll year = read(), month = read() - 1, day = read() - 1, x = read(), y = read(), z = read(), k = read();
		day += y_to_d(year) + m_to_d(isrun(year), month);
		k = k + d_to_s(x, y, z);
		ll nxt_day = day + k / mod;
		solve(nxt_day, k % mod);
	}
	return 0;
}
/*
9
1000 1 1 0 0 0 864000
1999 12 31 0 0 0 86400
1999 12 31 23 0 59 1
1970 1 1 8 0 0 1597379415
1970 1 1 8 0 0 32523136215
2000 1 1 0 0 0 3600
2000 2 28 23 59 59 1
2000 1 1 0 0 0 123456789
1000 1 1 0 0 0 10000000000
*/
