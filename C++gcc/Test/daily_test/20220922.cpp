
#include <iostream>
using namespace std;
int main()
{
    bool key = 1;
    while (key)
    {
        char a, b, c;
        cin >> a >> b >> c;
        char swap;
        if (a == (char)48 || b == (char)48 || c == (char)48)
        {
            key = 0;
            break;
        }
        if (a > b)
        {
            swap = a;
            a = b;
            b = swap;
            swap = 0;
        }
        if (b > c)
        {
            swap = b;
            b = c;
            c = swap;
            swap = 0;
        }
        if (a > b)
        {
            swap = a;
            a = b;
            b = swap;
            swap = 0;
        }
        cout << a << " " << b << " " << c << endl;
    }
    getchar();
    getchar();
    return 0;
}


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int x1, x2, y1, y2;
    bool key = 1;
    double S;
    double L;
    while (key)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0)
        {
            key = 0;
            break;
        }
        S = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        L = sqrt(S);
        cout << fixed << setprecision(2) << L << endl;
    }
    return 0;
}


#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double V[1000];
    int R_number;
    double R;
    cin >> R_number;
    for (int i = 0; i < R_number; i++)
    {
        R = 0;
        cin >> R;
        V[i] = (4  * (3.1415926535) * R * R * R)/3;
    }
    for (int i = 0; i < R_number; i++)
        cout << fixed << setprecision(3) << V[i] << endl;
        getchar();
        getchar();
    return 0;
}



#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int number;
    cin >> number;
    double enter_in;
    double amount[10000];
    for (int i = 0; i < number; i++)
    {
        enter_in = 0;
        cin >> enter_in;
        amount[i] = abs(enter_in);
    }
    for (int i = 0; i < number; i++)
        cout << fixed << setprecision(2) << amount[i] << endl;
    getchar();
    getchar();
    return 0;
}


#include <iostream>
using namespace std;
int main()
{
    int number;
    cin >> number;
    int grade[1000];
    for (int i = 0; i < number; i++)
        cin >> grade[i];
    for (int i = 0; i < number; i++)
    {
        if (grade[i] <= 100 && grade[i] >= 90)
        cout << "A" <<endl;
        else if (grade[i] <= 89 && grade[i] >= 80)
        cout << "B" <<endl;
        else if (grade[i] <= 79 && grade[i] >= 70)
        cout << "C" <<endl;
        else if (grade[i] <= 69 && grade[i] >= 60)
        cout << "D" <<endl;
        else if (grade[i] <= 59 && grade[i] >= 0)
        cout << "E" <<endl;
        else
        cout << "Score is error!";
    }
    getchar();
    getchar();
    return 0;
}


#include <iostream>
using namespace std;
int main()
{
    int times1;
    cin >> times1;
    int answer = 1;
    int array[7];
    int answer_array[100];
    for (int j = 0; j < times1; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            cin >> array[i];
            if (i > 0 && ((array[i] % 2) == 1) && i <= array[0])
                answer *= array[i];
        }
        answer_array[j] = answer;
        answer = 1;
    }
    for (int i = 0; i < times1; i++)
        cout << answer_array[i] << endl;
    getchar();
    getchar();
    return 0;
}

#include <iostream>
using namespace std;
long t, n, a, b, s;
long list[10000];
int main()
{
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        s = 1;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            if (a % 2 == 1)
                s = s * a;
        }
        list[j] = s;
    }
    for (int i = 1; i <= t; i++)
    {
        cout << list[i] << endl;
    }
    return 0;
}



#include <iostream>
using namespace std;
int main()
{
    int num, m, n, ans2, ans3;
    cin >> num;
    int array[100][2];
    for (int i = 0; i < num; i++)
    {
        ans2 = 0;
        ans3 = 0;
        cin >> m >> n;
        for (int j = m; j <= n; j++)
        {
            if ((j % 2) == 1)
                ans3 += j*j*j;
            else
                ans2 += j*j;
        }
        array[i][0] = ans2;
        array[i][1] = ans3;
    }
    for(int i = 0; i < 2; i++)
    cout << array[i][0] << " " << array[i][1] << endl;

    getchar();
    getchar();
    return 0;
}



#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    int num;
    double task;
    double array[1000];
    while (true)
    {
        a = 0;
        b = 0;
        c = 0;
        cin >> num;
        if (num == 0)
            break;
        for (int i = 0; i < num; i++)
        {
            cin >> task;
            if (task < 0)
                a += 1;
            else if (task == 0)
                b += 1;
            else
                c += 1;
        }
        cout << a << " " << b << " " << c << endl;
    }

    getchar ();
    getchar();
    return 0;
}
