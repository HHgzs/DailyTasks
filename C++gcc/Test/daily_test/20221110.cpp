#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        bool key = 0;
        for (int n = a; n <= b; n++)
        {
            int unit = n % 10;
            int ten = (n / 10) % 10;
            int hund = n / 100;
            if (n == hund * hund * hund + ten * ten * ten + unit * unit * unit)
            {
                key = 1;
                cout << n << " ";
            }
        }

        if (key ==0)
        cout << "no" ;
        cout << endl;
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int main()
// {
//     int T = 0;
//     cin >> T;
//     for (int i = 0; i < T; i++)
//     {
//         int n;
//         cin >> n;
//         vector<int> V1;
//         while (n != 0)
//         {
//             V1.push_back(n % 2);
//             n = n / 2;
//         }
//         vector<int> V2(V1);
//         reverse(V2.begin(), V2.end());
//         if (V1 == V2)
//             cout << "Yes" << endl;
//         else
//             cout << "No" << endl;
//     }
// }

// #include <iostream>
// #include <cmath>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int a = 0;
//         cin >> a;
//         long long b = pow(2, a) - 1;
//         cout << b << endl;
//     }
// }

// #include <iostream>
// #include <cmath>

// using namespace std;

// int attach_time(int &x0, int &y0, int x, int y)
// {
//     int time_in = static_cast<int>(sqrt((x0 - x) * (x0 - x) + (y0 - y) * (y0 - y)));
//     x0 = x;
//     y0 = y;
//     return time_in;
// }
// int attack_time(int hp, int ni)
// {
//     int time_in = 0, attack = 30;
//     if (ni > 3 && ni <= 8)
//         attack = 40;
//     if (ni > 8)
//         attack = 55;
//     time_in = hp / attack + (hp % attack > 0);
//     return time_in;
// }

// int main()
// {
//     int n = 0, x0 = 0, y0 = 0, sum = 0;
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         string name;
//         int hp, x, y;
//         cin >> name >> hp >> x >> y;
//         // cout << attach_time(x0, y0, x, y) << endl;
//         // cout << attack_time(hp, i) << endl;
//         sum += attach_time(x0, y0, x, y);
//         sum += attack_time(hp, i);
//     }
//     cout << sum;
// }

// #include <bits/stdc++.h>
// using namespace std;
// inline void read(long long &x)
// {
//     long long s = 0, w = 1;
//     char ch = getchar();
//     while (ch < '0' || ch > '9')
//     {
//         if (ch == '-')
//             w = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9')
//     {
//         s = (s << 3) + (s << 1) + (ch & 15);
//         ch = getchar();
//     }
//     x = s * w;
// }
// string nam;
// long long n, now = 30, tim, hp, x, y, nowx, nowy;
// int main()
// {
//     read(n);
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> nam;

//         tim += (long long)(sqrt((nowx - x) * (nowx - x) + (nowy - y) * (nowy - y)));
//         nowx = x, nowy = y;
//         if (i > 3)
//             now = 40;
//         if (i > 8)
//             now = 55;
//         tim += hp / now + (hp % now > 0);
//     }
//     cout << tim << endl;
// }

// #include <iostream>
// #include <cmath>

// using namespace std;

// inline void read(long long &x)
// {
//     long long s = 0, w = 1;
//     char ch = getchar();
//     while (ch < '0' || ch > '9')
//     {
//         if (ch == '-')
//             w = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9')
//     {
//         s = (s << 3) + (s << 1) + (ch & 15);
//         ch = getchar();
//     }
//     x = s * w;
// }
// string name;
// long long n = 0, attack = 30, x0 = 0, y0 = 0, sum = 0, hp, x, y;
// int main()
// {

//     read(n);
//     for (int i = 0; i < n; i++)
//     {

//         cin >> name;
//         read(hp), read(x), read(y);
//         sum += (long long)(sqrt((x0 - x) * (x0 - x) + (y0 - y) * (y0 - y)));
//         x0 = x;
//         y0 = y;
//         if (i > 3)
//             attack = 40;
//         if (i > 8)
//             attack = 55;
//         sum += hp / attack + (hp % attack > 0);
//     }
//     cout << sum << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;
// void read(long long &x)
// {
//     long long s = 0, w = 1;
//     char ch = getchar();
//     while (ch < '0' || ch > '9')
//     {
//         if (ch == '-')
//             w = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9')
//     {
//         s = (s << 3) + (s << 1) + (ch & 15);
//         ch = getchar();
//     }
//     x = s * w;
// }
// string nam;
// long long n, now = 30, tim, hp, x, y, nowx, nowy;
// int main()
// {
//     read(n);
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> nam;
//         read(hp), read(x), read(y);
//         tim += (long long)(sqrt((x0 - x) * (x0 - x) + (nowy - y) * (nowy - y)));
//         nowx = x, nowy = y;
//         if (i > 3)
//             now = 40;
//         if (i > 8)
//             now = 55;
//         tim += hp / now + (hp % now > 0);
//     }
//     cout << tim << endl;
// }
