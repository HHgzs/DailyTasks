#include <iostream>
#include <vector>
#include <map>
using namespace std;

void cinit_enter(multimap<long long, int> &, multimap<long long, int> &, int);
void cnew_make(multimap<long long, int> &, map<int, int> &, int &);
void cexist_resize(vector<vector<bool>> &, int, int);
void cexist_make(map<int, int> &, map<int, int> &, vector<int> &, vector<int> &, vector<vector<bool>> &, int, int, int);
void cnum_make(vector<vector<int>> &, vector<vector<bool>> &, vector<int> &, vector<int> &, int, int, int);
void display(vector<vector<int>> &, vector<vector<bool>> &, int, int);
void calculate(vector<vector<int>> &, vector<int> &, vector<int> &, int, int, int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, W, H;
    long long m;
    multimap<long long, int> x_init;
    multimap<long long, int> y_init;
    map<int, int> x_new;
    map<int, int> y_new;
    vector<vector<bool>> c_exist;
    vector<vector<int>> c_num;
    vector<int> x_newv, y_newv;
    cin >> n >> m;
    cinit_enter(x_init, y_init, n);
    cnew_make(x_init, x_new, W);
    cnew_make(y_init, y_new, H);
    cexist_resize(c_exist, W, H);
    cexist_make(x_new, y_new, x_newv, y_newv, c_exist, W, H, n);
    cnum_make(c_num, c_exist, x_newv, y_newv, W, H, n);
    while (m--)
        calculate(c_num, x_newv, y_newv, n, W, H);
}

void cinit_enter(multimap<long long, int> &x_init, multimap<long long, int> &y_init, int n)
{
    for (int i = 0; i < n; i++)
    {
        long long x0, y0;
        cin >> x0 >> y0;
        x_init.insert(pair<long long, int>(x0, i));
        y_init.insert(pair<long long, int>(y0, i));
    }
}
void cnew_make(multimap<long long, int> &c_init, map<int, int> &c_new, int &WH)
{
    WH = 0;
    multimap<long long, int>::iterator iter;
    long long c0 = 0;
    long long c1 = c_init.begin()->first;
    for (iter = c_init.begin(); iter != c_init.end(); iter++)
    {
        c0 = iter->first;
        if (c0 > c1)
            WH++;
        c_new.insert(pair<int, int>(iter->second, WH));
        c1 = c0;
    }
}
void cexist_resize(vector<vector<bool>> &c_exist, int W, int H)
{
    c_exist.resize(H + 1);
    for (int i = 0; i <= H; i++)
        c_exist[i].resize(W + 1);
}
void cexist_make(map<int, int> &x_new, map<int, int> &y_new,
                 vector<int> &x_newv, vector<int> &y_newv, vector<vector<bool>> &c_exist, int W, int H, int n)
{
    x_newv.resize(W + 1);
    y_newv.resize(H + 1);
    map<int, int>::iterator x_it, y_it;
    for (x_it = x_new.begin(); x_it != x_new.end(); x_it++)
    {
        x_newv[x_it->first] = x_it->second;
    }
    for (y_it = y_new.begin(); y_it != y_new.end(); y_it++)
    {
        y_newv[y_it->first] = y_it->second;
    }
    for (int i = 0; i < n; i++)
    {
        c_exist[y_newv[i]][x_newv[i]] = 1;
    }
}
void cnum_make(vector<vector<int>> &c_num, vector<vector<bool>> &c_exist, vector<int> &x_newv, vector<int> &y_newv, int W, int H, int n)
{
    c_num[0][0] = c_exist[0][0];
    for (int i = 1; i <= H; i++)
    {
        c_num[i][0] = c_num[i - 1][0] + c_exist[i][0];
    }
    for (int j = 1; j <= W; j++)
    {
        c_num[0][j] = c_num[0][j - 1] + c_exist[0][j];
    }
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            c_num[i][j] = c_num[i - 1][j] + c_num[i][j - 1] - c_num[i - 1][j - 1] + c_exist[i][j];
        }
    }
}
void display(vector<vector<int>> &c_num, vector<vector<bool>> &c_exist, int W, int H)
{
    for (int i = 0; i <= H; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            cout << c_num[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i <= H; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            cout << c_exist[i][j] << " ";
        }
        cout << endl;
    }
}
void calculate(vector<vector<int>> &c_num, vector<int> &x_newv, vector<int> &y_newv, int n, int W, int H)
{
    int c1_find, c2_find;
    cin >> c1_find >> c2_find;
    int sum = 0;
    map<int, int>::iterator x1_it, y1_it, x2_it, y2_it;
    int x1 = x_newv[c1_find], y1 = y_newv[c1_find];
    int x2 = x_newv[c2_find], y2 = y_newv[c2_find];
    sum = c_num[y2][x2] - c_num[y2][x1 - 1] - c_num[y1 - 1][x2] + c_num[y1 - 1][x1 - 1];
    cout << sum;
}