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
    static bool compares_int(vector<int>, vector<int>);
    static bool compares_double_1(vector<double>, vector<double>);
    static bool compares_double_0(vector<double>, vector<double>);
    static bool compares(vector<long long>, vector<long long>);
    void sort_average();
    void sort_average_back();
    void sort_credits();
    void sort_grades();
    void display();

public:
    static vector<vector<int>> credits;
    static vector<vector<double>> average;
    static vector<vector<long long>> grades;
    vector<string> names;
    static int n;
};

Grade::Grade()
{
    credits.resize(6);
    credits[0].push_back(0);
    credits[0].push_back(10000);
    for (int i = 1; i <= 5; i++)
    {
        credits[i].resize(2);
        credits[i][0] = i;
    }
}

bool Grade::compares_int(vector<int> a, vector<int> b)
{
    if (a[1] != b[1])
        return a[1] > b[1];
    else
        return 1;
}

bool Grade::compares_double_1(vector<double> a, vector<double> b)
{
    if (a[1] != b[1])
        return a[1] > b[1];
    else
        return 1;
}

bool Grade::compares_double_0(vector<double> a, vector<double> b)
{
    if (a[0] != b[0])
        return a[0] < b[0];
    else
        return 1;
}

bool Grade::compares(vector<long long> a, vector<long long> b)
{
    // for (int i = 1; i < 6; i++)
    //     cout << credits[i][0] << " " << credits[i][1] << endl;

    if (a[6] != b[6])
    {
        // cout << a[0] << " " << b[0] << " " << a[6] << " " << b[6] << std::endl;
        return a[6] > b[6];
    }

    // cout << 1 << credits[1][0] << credits[1][0] << endl;
    if (a[credits[1][0]] != b[credits[1][0]])
    {
        // cout << a[0] << " " << b[0] << " " << a[credits[1][0]] << " " << b[credits[1][0]] << std::endl;
        return a[credits[1][0]] > b[credits[1][0]];
    }

    // cout << 2 << credits[2][0] << credits[2][0] << endl;
    if (a[credits[2][0]] != b[credits[2][0]])
    {
        // cout << a[0] << " " << b[0] << " " << a[credits[2][0]] << " " << b[credits[2][0]] << std::endl;
        return a[credits[2][0]] > b[credits[2][0]];
    }

    // cout << 3 << credits[3][0] << credits[3][0] << endl;
    if (a[credits[3][0]] != b[credits[3][0]])
    {
        // cout << a[0] << " " << b[0] << " " << a[credits[3][0]] << " " << b[credits[3][0]] << std::endl;
        return a[credits[3][0]] > b[credits[3][0]];
    }

    // cout << 4 << credits[4][0] << credits[4][0] << endl;
    if (a[credits[4][0]] != b[credits[4][0]])
    {
        // cout << a[0] << " " << b[0] << " " << a[credits[4][0]] << " " << b[credits[4][0]] << std::endl;
        return a[credits[4][0]] > b[credits[4][0]];
    }

    // cout << 5 << credits[5][0] << credits[5][0] << endl;
    return a[credits[5][0]] > b[credits[5][0]];
}

void Grade::sort_average()
{
    sort(average.begin(), average.end(), Grade::compares_double_1);
}

void Grade::sort_average_back()
{
    sort(average.begin(), average.end(), Grade::compares_double_0);
}

void Grade::sort_credits()
{
    sort(credits.begin() + 1, credits.end(), Grade::compares_int);
}

void Grade::sort_grades()
{
    sort(grades.begin(), grades.end(), Grade::compares);
}

void Grade::display()
{
    for (int i = 0; i < n; i++)
    {
        cout << names[grades[i][0]] << " ";
        cout << fixed << setprecision(2) << average[grades[i][0]][1] << endl;
    }
}

vector<vector<int>> Grade::credits;
vector<vector<double>> Grade::average;
vector<vector<long long>> Grade::grades;
int Grade::n;

int main()
{
    double cre_sum;
    Grade g;
    for (int i = 1; i <= 5; i++)
    {
        int a;
        cin >> a;
        Grade::credits[i][1] = a;
        cre_sum += a;
    }

    cin >> Grade::n;
    Grade::grades.resize(Grade::n);
    Grade::average.resize(Grade::n);

    for (int i = 0; i < Grade::n; i++)
    {
        string str;
        cin >> str;
        g.names.push_back(str);
        long long a, b, c, d, e;
        double ave = 0;
        cin >> a >> b >> c >> d >> e;

        Grade::grades[i].push_back(i);
        Grade::grades[i].push_back(a);
        Grade::grades[i].push_back(b);
        Grade::grades[i].push_back(c);
        Grade::grades[i].push_back(d);
        Grade::grades[i].push_back(e);

        Grade::average[i].push_back(i);
        for (int j = 1; j <= 5; j++)
            ave += Grade::grades[i][j] * Grade::credits[j][1];
        ave /= cre_sum;
        Grade::average[i].push_back(ave);
    }

    g.sort_average();

    int ranking = Grade::n;
    Grade::average[0].push_back(ranking);
    for (int i = 1; i < Grade::n; i++)
    {
        if (Grade::average[i][1] == Grade::average[i - 1][1])
            Grade::average[i].push_back(ranking);
        else
            Grade::average[i].push_back(--ranking);
    }

    for (int i = 0; i < Grade::n; i++)
        Grade::grades[static_cast<long long>(Grade::average[i][0])].push_back(static_cast<long long>(Grade::average[i][2]));

    g.sort_credits();
    g.sort_grades();
    g.sort_average_back();
    g.display();
}