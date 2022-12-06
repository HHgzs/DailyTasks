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
    static bool compares_int(int, int);
    static bool compares_double_1(vector<double>, vector<double>);
    static bool compares_double_0(vector<double>, vector<double>);
    static bool compares(vector<long long>, vector<long long>);
    void sort_together();
    void display();

public:
    static vector<int> credits;
    static vector<vector<double>> average;
    static vector<vector<long long>> grades;
    vector<string> names;
    static int n;
};

Grade::Grade()
{
    credits.resize(6);
    credits[0] = 10000;
}

bool Grade::compares_int(int a,int b)
{
    return a > b;
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
    if (a[6] != b[6])
        return a[6] > b[6];
    if (a[1] != b[1])
        return a[1] > b[1];
    if (a[2] != b[2])
        return a[2] > b[2];
    if (a[3] != b[3])
        return a[3] > b[3];
    if (a[4] != b[4])
        return a[4] > b[4];
    return a[5] > b[5];
}

void Grade::sort_together()
{
    for (int i = 1; i < 5; i++)
    {
        for (int j = 1; j < 5 - i; j++)
        {
            if (credits[j] < credits[j + 1])
            {
                int temp = credits[j];
                credits[j] = credits[j + 1];
                credits[j + 1] = temp;
                for (int k = 0; k < Grade::n; k++)
                {
                    long long tempv = grades[k][j];
                    grades[k][j] = grades[k][j + 1];
                    grades[k][j + 1] = tempv;
                }
            }
        }
    }
}

void Grade::display()
{
    for (int i = 0; i < n; i++)
    {
        cout << names[grades[i][0]] << " ";
        cout << fixed << setprecision(2) << average[grades[i][0]][1] << endl;
    }
}

vector<int> Grade::credits;
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
        Grade::credits[i] = a;
        cre_sum += a;
    }

    cin >> Grade::n;
    Grade::grades.resize(Grade::n);
    Grade::average.resize(Grade::n);

    for (int i = 0; i < Grade::n; i++)
    {
        string str;
        double ave = 0;
        cin >> str;
        g.names.push_back(str);
        Grade::grades[i].resize(6);
        Grade::grades[i][0] = i;

        for (int j = 1; j <= 5; j++)
        {
            cin >> Grade::grades[i][j];
            ave += Grade::grades[i][j] * Grade::credits[j];
        }
        ave /= cre_sum;

        Grade::average[i].push_back(i);
        Grade::average[i].push_back(ave);
    }

    sort(Grade::average.begin(), Grade::average.end(), Grade::compares_double_1);
    g.sort_together();
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

    sort(Grade::credits.begin() + 1, Grade::credits.end(), Grade::compares_int);
    sort(Grade::grades.begin(), Grade::grades.end(), Grade::compares);
    sort(Grade::average.begin(), Grade::average.end(), Grade::compares_double_0);
    g.display();


    getchar();
    getchar();
    getchar();
}