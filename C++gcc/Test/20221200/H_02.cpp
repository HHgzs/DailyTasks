#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

void cinit_enter(multimap<long long, int> &, multimap<long long, int> &, int);
void cnew_make(multimap<long long, int> &, map<int, int> &, int &);
void cexist_resize(vector<vector<bool>> &, int, int);
void cexist_make(map<int, int> &, map<int, int> &, vector<vector<bool>> &, int, int);
void cnum_make(vector<vector<int>> &, map<int, int> &, map<int, int> &, vector<vector<bool>> &, vector<int> &, vector<int> &, int64_t);
void calculate(map<int, int> &, map<int, int> &, map<int, int> &, int, int, int, int, int);

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
    cexist_make(x_new, y_new, c_exist, W, H);
    cnum_make(c_num, x_new, y_new, c_exist, W, H, n);
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
    c_exist.resize(W + 1);
    for (int i = 0; i <= W; i++)
        c_exist[i].resize(H);
}

void cexist_make(map<int, int> &x_new, map<int, int> &y_new, vector<vector<bool>> &c_exist, int W, int H)
{
    map<int, int>::iterator x_it;
    map<int, int>::iterator y_it;
    for (x_it = x_new.begin(); x_it != x_new.end(); x_it++)
    {
        for (y_it = y_new.begin(); y_it != y_new.end(); y_it++)
        {
            c_exist[x_it->second][y_it->second] = 1;
        }
    }
}

void cnum_make(vector<vector<int>> &c_num, map<int, int> &x_new, map<int, int> &y_new,
               vector<vector<bool>> &c_exist, vector<int> &x_newv, vector<int> &y_newv, int n)
{
    map<int, int>::iterator x_it, y_it, c_it;
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
        x_it = x_new.find(i);
        y_it = y_new.find(i);

        for (int ix = 0; ix <= x_newv[i]; ix++)
        {
            for (int iy = 0; iy <= y_it->second; iy++)
            {
                if (c_exist[ix][iy])
                    c_num[ix][iy]++;
            }
        }
    }
}

void calculate(vector<vector<int>> &c_num, map<int, int> &x_new, map<int, int> &y_new,
               int c1_find, int c2_find, int n, int W, int H)
{
    map<int, int>::iterator x1_it, y1_it, x2_it, y2_it;
    x1_it = x_new.find(c1_find);
    y1_it = y_new.find(c1_find);
    x1_it = x_new.find(c2_find);
    y1_it = y_new.find(c2_find);
}