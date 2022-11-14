
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int prime[10000];
    prime[0] = 2;
    int amount = 1;
    bool key = 1;
    bool is_prime[100000];
    for (int i = 0; i < 100000; i++)
    {
        is_prime[i] = 0;
    }
    for (int j = 3; j < 100000; j += 2)
    {
        key = 1;
        for (int i = 0; i < amount; i++)
        {
            if (j % prime[i] == 0)
            {
                key = 0;
            }
        }
        if (key == 1)
        {
            prime[amount] = j;
            amount++;
        }
    }
    for (int i = 0; i < amount; i++)
        is_prime[prime[i] - 1] = 1;

    ofstream output;
    output.open("code.txt");

    for (int i = 0; i < 100000; i++)
    {
        output << "    if ( n == " << i+1 << " ){" << endl;

        if (is_prime[i] == 1)
        {

            output << "        cout << \" " << i+1 << " \""
                   << "<< \"is a prime\""
                   << ";" << endl;
            output << "        return 1;\n"
                   << "    }" << endl;
        }
        else
        {
            output << "        cout << \" " << i+1 << " \""
                   << "<< \"is not a prime\""
                   << ";" << endl;
            output << "        return 0;\n"
                   << "    }" << endl;
        }
    }
    output.close();
    getchar();
}





#include <iostream>
using namespace std;
void calculate(int sum , int n, int array[], int array_eq[])
{
    int i0 = 0;
    if (sum % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (array[j] == (array[i] + (sum / 2)) && (array[i] <= (sum / 2 + array[0])))
                {
                    array_eq[i0] = array[i];
                    i0++;
                }
            }
        }
        if (i0 > 1)
            cout << ((i0 - 1) * i0) / 2;
        else
            cout << "0";
    }
    else
        cout << "0";
}
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    if (n <= 20)
    {
        int array[20];
        int array_eq[10];
    }
    else if (n <= 5000 && n > 20)
    {
        int array[5000];
        int array_eq[2500];
    }
    else
    {
        int array[200000];
        int array_eq[100000];
    }
    for (int i = 0; i < n; i++)
    {
        int a1;
        cin >> a1;
        sum += a1;
        array[i] = sum;
    }
    calculate(sum, n, array, array_eq);
}




#include <iostream>
using namespace std;

void calculate(int sum , int n, int *array)
{
    int b=0;
    int *array_eq = &b;
    int i0 = 0;
    if (sum % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (array[j] == (array[i] + (sum / 2)) && (array[i] <= (sum / 2 + array[0])))
                {
                    *(array_eq + i0) = array[i];
                    i0++;
                    cout << i0 << endl;
                }
            }
        }
        if (i0 > 1)
            cout << ((i0 - 1) * i0) / 2;
        else
            cout << "0";
    }
    else
        cout << "0";
}
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int a=0;
    int *array = &a;
    for (int i = 0; i < n; i++)
    {
        int a1;
        cin >> a1;
        sum += a1;
        *(array + i) = sum;
    }
    calculate(sum, n, array);
}





#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int *array = new int[n];
    int a1;
    for (int i = 0; i < n; i++)
    {
        cin >> a1;
        sum += a1;
        *(array + i) = sum;
    }
    int *array_eq = new int[n];
    int i0 = 0;
    if (sum % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (array[j] == (array[i] + (sum / 2)) && (array[i] <= (sum / 2 + array[0])))
                {
                    *(array_eq + i0) = array[i];
                    i0++;
                    //cout << i0 << endl;
                }
            }
        }
        if (i0 > 1)
            cout << ((i0 - 1) * i0) / 2;
        else
            cout << "0";
    }
    else
        cout << "0";
}




#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0, num = 0, enter_num;
    int *array = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> enter_num;
        sum += enter_num;
        *(array + i) = sum;
    }
    for (int i = 0; i < n; i++)
    {
        if (array[i] >= (sum / 2 + array[0]))
            break;
        for (int j = i + 1; j < n; j++)
            if (array[j] == (array[i] + (sum / 2)))
                num++;
    }
    delete array;
    cout << ((num - 1) * num) / 2;
}




#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = 0, num = 0, enter_num;
    int *array = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        sum += enter_num;
        *(array + i) = sum;
    }
    int p = sum / 2;
    int q = p + array[0];
    for (int i = 0; i < n; i++)
    {
        if (array[i] >= q)
            break;
        for (int j = i + 1; j < n; j++)
            if (array[j] == (array[i] + p))
                num++;
    }
    delete array;
    cout << ((num - 1) * num) / 2;
}





#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = 0, num = 0, temporary_sum, half;
    int *array = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        sum += array[i];
    }
    half = sum / 2;
    for (int i = 0; i < n-1; i++)
    {
        temporary_sum = 0;
        for (int j = i; j < n-1; j++)
        {
            temporary_sum += array[j];
            if (temporary_sum > half)
                break;
            else if (temporary_sum == half)
            {
                num++;
                break;
            }
        }
    }
    delete array;
    cout << ((num - 1) * num) / 2;
}





#include <bits/stdc++.h>
#define N 200020
using namespace std;
inline void read(long long &x)
{
    long long s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = (s << 3) + (s << 1) + (ch & 15);
        ch = getchar();
    }
    x = s * w;
}
long long n, sum, r, edge[N], pnt[N];
int main()
{
    read(n);
    for (long long i = 1; i <= n; i++)
        read(edge[i]), r += edge[i];
    for (long long i = 1; i <= n; i++)
        pnt[i] = pnt[i - 1] + edge[i];
    if (r & 1)
    {
        puts("0");
        return 0;
    }
    for (long long i = 0; i < n; i++)
    {
        if (pnt[lower_bound(pnt, pnt + n, (pnt[i] + r / 2) % r) - pnt] == (pnt[i] + r / 2))
            sum++;
    }
    cout << sum * (sum - 1) / 2 << endl;
}
