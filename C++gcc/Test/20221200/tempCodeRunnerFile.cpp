#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

bool compares(vector<double> a, vector<double> b)
{
    if (a[6] != b[6])
        return a[6] > b[6];
    else
    {
        if (a[1] != b[1])
            return a[1] > b[1];
        else
        {
            if (a[2] != b[2])
                return a[2] > b[2];
            else
            {
                if (a[3] != b[3])
                    return a[3] > b[3];
                else
                {
                    if (a[4] != b[4])
                        return a[4] > b[4];
                    else
                        return a[5] > b[5];
                }
            }
        }
    }
}

int main()
{
    vector<vector<double>> grades;
    vector<double> credits(1, 0);
    vector<string> names;

    double cre_sum;
    for (int i = 0; i < 5; i++)
    {
        double a;
        cin >> a;
        credits.push_back(a);
        cre_sum += a;
    }
    int n;
    cin >> n;
    grades.resize(n);
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        names.push_back(str);
        double a, b, c, d, e, ave;
        ave = 0;
        cin >> a >> b >> c >> d >> e;
        grades[i].push_back(i);
        grades[i].push_back(a);
        grades[i].push_back(b);
        grades[i].push_back(c);
        grades[i].push_back(d);
        grades[i].push_back(e);
        for (int j = 1; j <= 5; j++)
        {
            ave += grades[i][j] * credits[j] / cre_sum;
        }
        grades[i].push_back(ave);
    }
    sort(grades.begin(), grades.end(), compares);
    for (int i = 0; i < n; i++)
    {
        cout << names[grades[i][0]] << " " << fixed << setprecision(2) <<grades[i][6] << endl;
    }
}