/*
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    double x1,y1,x2,y2,a;
    cin >> x1>>y1>>x2 >>y2;
    a=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    cout << fixed << setprecision(4)<<pow(a,0.5)<<endl;
}



#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(8) << 0.5 * a * b * sin(c*0.0174532925199433) << endl;
    cout << fixed << setprecision(8) << pow((a * a + b * b - 2 * a * b * cos(c*0.0174532925199433)), 0.5)+a+b << endl;
    cout << fixed << setprecision(8) << (a * b * sin(c*0.0174532925199433)) / a << endl;
}



#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    int a,total;
    double average,A;

    int box[1000];
    cin >> a;
    while(a != 0)
    {
        total = 0;
        A=0;
        for (int i = 0; i < a ; i++ )
        {
            cin >> box[i];
            total += box[i];
        }
        average = total/a;
        for (int i = 0; i< a ; i++)
        {
            A += ((box[i]-average)*(box[i]-average));
        }
        cout << fixed << setprecision(8) <<sqrt(A/a) << endl;
        cin >> a;
    }
}


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void calculate(double array1[], double array2[], int n, int p)
{
    double total = 0;
    for (int i = 0; i < n; i++)
        total += pow(abs(array1[i] - array2[i]), p);
    if (p == 1)
        cout << fixed << setprecision(6) << total;
    else if (p == 2)
        cout << fixed << setprecision(6) << sqrt(total);
    else
        cout << fixed << setprecision(6) << cbrt(total);
    cout << endl;
}
void compare(double array1[], double array2[], int n)
{

    double array3[120];
    for (int i = 0; i < n; i++)
        array3[i] = abs(array1[i] - array2[i]);
    double test = array3[0];
    for (int i = 0; i < n; i++)
    {
        if (array3[i] > test)
            test = array3[i];
    }
    cout << fixed << setprecision(6) << test << endl;
}

int main()
{
    int n;
    cin >> n;
    double array1[120], array2[120];
    for (int i = 0; i < n; i++)
        cin >> array1[i];
    for (int i = 0; i < n; i++)
        cin >> array2[i];
    calculate(array1, array2, n, 1);
    calculate(array1, array2, n, 2);
    calculate(array1, array2, n, 3);
    compare(array1, array2, n);
}




#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    int b = a;
    for (int i = 0; i < a; i++)
    {

        for (int j = 0; j < b - 1; j++)
        {
            cout << " ";

        }
        b--;
        for (int j = 0; j < (2 * i + 1); j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}


#include <iostream>
using namespace std;
int main()
{
    int box[1000];
    int num;
    cin >> num;
    int text = 0;
    int swap = 0;
    int key = 0;
    while (num != 0)
    {
        key = 0;
        for (int i = 0; i < num; i++)
        {
            cin >> box[i];
        }
        for (int i = 0; i < num; i++)
        {
            text = box[0];
            if (box[i] < text)
            {
                text = box[i];
                key = i;
            }
        }
        swap = box[0];
        box[0] = box[key];
        box[key] = swap;
        for (int i = 0; i < num; i++)
        {
            cout << box[i] << " ";
        }
        cout << endl;
        cin >> num;
    }
}




#include <iostream>
using namespace std;
int main()
{
    long long m, n, a;
    long long box[1000];
    cin >> m >> n;

    while (m != 0 && n != 0)
    {
        // a = m;
        for (int i = 0; i < m; i++)
        {
            cin >> box[i];
            // if (box[i] > n)
            //     a = i;
        }
        if (n < box[0])
            cout << n << " ";
        for (int i = 0; i < m; i++)
        {
            cout << box[i] << " ";
            if (n >= box[i] && n <= box[i + 1])
                // if (i == a - 1 && n > box[0] && n < box[m - 1])
                cout << n << " ";
        }
        if (n > box[m - 1])
            cout << n << " ";
        cout << endl;
        cin >> m >> n;
    }
}


#include <iostream>
using namespace std;
int main()
{
    int rr, cc, r1, c1;
    cin >> rr >> cc;
    int array[1000][1000];
    int max = -1;
    for (int i = 0; i < rr; i++)
    {
        for (int j = 0; j < cc; j++)
        {
            cin >> array[i][j];
            if (abs(array[i][j]) > max)
            {
                r1 = i;
                c1 = j;
                max = abs(array[i][j]);
            }
        }
    }
    cout << r1 + 1 << " "<< c1 + 1  << " "<< array[r1][c1];
}



#include<iostream>
using namespace std;
int main()
{
    string word;
    int num;
    cin >> num;
    for (int i = 0; i < num ; i++)
    {
        cin >> word;
        char max = word[0];
        for (int j = 0 ; j < word.length() ; j ++)
        {
            if (word[j] > max)
            max = word[j];
        }
        for (int j = 0; j < word.length(); j++)
        {
            cout << word[j];
            if (word[j] == max)
            cout << "(max)";
        }
        cout << endl;
    }
}


*/

#include <iostream>
using namespace std;

bool test(int num)
{
    int basic = num;
    int temp = 0;
    while (num != 0)
    {
        temp = temp * 10 + num % 10;
        num /= 10;
    }
    if (temp == basic)
        return 1;
    else
        return 0;
}
int main()
{
    int prime[1000];
    prime[0] = 2;
    int amount = 1;
    bool key = 1;
    for (int j = 3; j < 1000; j += 2)
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
    // for (int i = 0; i < amount; i++)
    //    cout << prime[i] << endl;

    int a, b;
    cin >> a >> b;
    while (a != 0 && b != 0)
    {
        for (int i = 0; i < amount; i++)
        {
            if (test(prime[i]) == 1 && a <= prime[i] && b >= prime[i])
                cout << prime[i] << endl;
        }
        cout << endl;
        cin >> a >> b;
    }
}