#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    double x = (0.3141592653589);
    double sum = 0;
    for (int i = 0; i < 4; i++)
    {
        int a = 1;
        for (int j = 1; j <= (2*i+1); j++)
            a *= j;
        
        if (i%2 == 0)
        sum += ((pow(x, (2 * i + 1))) / a);
        else
        sum -= ((pow(x, (2 * i + 1))) / a);
    }
    cout << fixed <<  setprecision(8) << sum;
}