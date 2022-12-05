#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

class Grade
{
public:
    Grade();
    static bool compares_credits(vector<double>, vector<double>);
    static bool compares(vector<double>, vector<double>);
    static bool compares_last(vector<double>, vector<double>);
    void sort_credits();
    void sort_grades();
    void display();

public:
    static vector<vector<double>> credits;
    vector<vector<double>> grades;
    vector<string> names;
    int n;
};

Grade::Grade()
{
    credits.resize(6);
    credits[0].push_back(0);
    credits[0].push_back(10000);
    for (int i = 1; i <= 5; i++)
    {
        credits[i].resize(2);
        credits[i][0] = static_cast<double>(i);
    }
}

bool Grade::compares_credits(vector<double> a, vector<double> b)
{
    if (a[1] != b[1])
        return a[1] > b[1];
    else
        return 0;
}

bool Grade::compares(vector<double> a, vector<double> b)
{
    if (a[6] != b[6])
        return a[6] > b[6];
    else
    {
        if (a[credits[1][0]] != b[credits[1][0]])
            return a[credits[1][0]] > b[credits[1][0]];
        else
        {
            if (a[credits[2][0]] != b[credits[2][0]])
                return a[credits[2][0]] > b[credits[2][0]];
            else
            {
                if (a[credits[3][0]] != b[credits[3][0]])
                    return a[credits[3][0]] > b[credits[3][0]];
                else
                {
                    if (a[credits[4][0]] != b[credits[4][0]])
                        return a[credits[4][0]] > b[credits[4][0]];
                    else
                        return a[credits[5][0]] > b[credits[5][0]];
                }
            }
        }
    }
}

bool Grade::compares_last(vector<double> a, vector<double> b)
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

void Grade::sort_credits()
{
    sort(credits.begin(), credits.end(), Grade::compares_credits);
}

void Grade::sort_grades()
{
    sort(grades.begin(), grades.end(), Grade::compares);
}

void Grade::display()
{
    for (int i = 0; i < n; i++)
    {
        cout << names[grades[i][0]] << " " << fixed << setprecision(2) << grades[i][6] << endl;
    }
}

vector<vector<double>> Grade::credits;

int main()
{
    double cre_sum;
    Grade g;
    for (int i = 1; i <= 5; i++)
    {
        double a;
        cin >> a;
        g.credits[i][1] = a;
        cre_sum += a;
    }

    cin >> g.n;
    g.grades.resize(g.n);

    for (int i = 0; i < g.n; i++)
    {
        string str;
        cin >> str;
        g.names.push_back(str);
        double a, b, c, d, e, ave;
        ave = 0;
        cin >> a >> b >> c >> d >> e;
        g.grades[i].push_back(i);
        g.grades[i].push_back(a);
        g.grades[i].push_back(b);
        g.grades[i].push_back(c);
        g.grades[i].push_back(d);
        g.grades[i].push_back(e);
        for (int j = 1; j <= 5; j++)
            ave += g.grades[i][j] * g.credits[j][1] / cre_sum;
        g.grades[i].push_back(ave);
    }
    g.sort_grades();
    g.sort_credits();
    g.display();
}