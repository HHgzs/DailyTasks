
#include <iostream>
using namespace std;
int main()
{
    int a;
    int b = 1;
    int c = 1;
    cin >> a;
    cout << "1" << endl;
    if (a == 2)
        cout << "1" << endl;
    else if (a > 2)
    {
        cout << "1" << endl;
        for (int i = 0; i < a - 2; i++)
        {
            int d = b + c;
            b = c;
            c = d;
            cout << d << endl;
        }
    }
}