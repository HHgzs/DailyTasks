#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

void cinit_enter(multimap<long long, int> &, multimap<long long, int> &, int);
void cnew_make(multimap<long long, int> &, map<int, int> &, int &);
void resize_double(vector<vector<bool>> &, vector<vector<int>> &, int, int);
void cexist_make(map<int, int> &, map<int, int> &, vector<int> &, vector<int> &, vector<vector<bool>> &, int, int, int);
void cnum_make(vector<vector<int>> &, vector<vector<bool>> &, int, int, int);
void calculate(vector<vector<int>> &, vector<int> &, vector<int> &, int, int, int);
void print_init(multimap<long long, int> &, multimap<long long, int> &);
void print_new(map<int, int>, map<int, int>);
void print_newv(vector<int>, vector<int>, int);
void print_nWH(int, int, int);
void print_exist(vector<vector<bool>> &, int, int);
void print_num(vector<vector<int>> &, int, int);
void print_double(vector<vector<int>> &, vector<vector<bool>> &, int, int);

int main()
{
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
    print_init(x_init, y_init);
    print_new(x_new, y_new);

    resize_double(c_exist, c_num, W, H);
    cexist_make(x_new, y_new, x_newv, y_newv, c_exist, W, H, n);
    cnum_make(c_num, c_exist, W, H, n);
    print_nWH(W, H, n);
    print_newv(x_newv, y_newv, n);
    print_double(c_num, c_exist, W, H);
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
void resize_double(vector<vector<bool>> &c_exist, vector<vector<int>> &c_num, int W, int H)
{
    c_exist.resize(H + 1);
    for (int i = 0; i <= H; i++)
        c_exist[i].resize(W + 1);
    c_num.resize(H + 2);
    for (int i = 0; i <= H + 1; i++)
        c_num[i].resize(W + 2);
}
void cexist_make(map<int, int> &x_new, map<int, int> &y_new, vector<int> &x_newv, vector<int> &y_newv, vector<vector<bool>> &c_exist, int W, int H, int n)
{
    x_newv.resize(n);
    y_newv.resize(n);
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
void cnum_make(vector<vector<int>> &c_num, vector<vector<bool>> &c_exist, int W, int H, int n)
{
    for (int i = 0; i <= H + 1; i++)
        c_num[i][0] = 0;
    for (int j = 1; j <= W + 1; j++)
        c_num[0][j] = 0;
    for (int i = 1; i < H + 2; i++)
    {
        for (int j = 1; j < W + 2; j++)
        {
            c_num[i][j] = c_num[i - 1][j] + c_num[i][j - 1] - c_num[i - 1][j - 1] + c_exist[i - 1][j - 1];
        }
    }
}
void calculate(vector<vector<int>> &c_num, vector<int> &x_newv, vector<int> &y_newv, int n, int W, int H)
{
    int c1_find, c2_find;
    cin >> c1_find >> c2_find;
    int sum = 0;
    int x1 = x_newv[c1_find] + 1, y1 = y_newv[c1_find] + 1;
    int x2 = x_newv[c2_find] + 1, y2 = y_newv[c2_find] + 1;

    sum = c_num[y2][x2] - c_num[y2][x1 - 1] - c_num[y1 - 1][x2] + c_num[y1 - 1][x1 - 1];
    cout << sum << endl;
}

void print_init(multimap<long long, int> &x_init, multimap<long long, int> &y_init)
{
    multimap<long long, int>::iterator it;
    cout << "\n    init_x   order\n";
    cout << "  __________________\n";
    for (it = x_init.begin(); it != x_init.end(); it++)
        cout << right << setw(10) << it->first << right << setw(4) << it->second << endl;
    cout << "\n    init_y   order\n";
    cout << "  __________________\n";
    for (it = y_init.begin(); it != y_init.end(); it++)
        cout << right << setw(10) << it->first << right << setw(4) << it->second << endl;
    cout << endl;
}
void print_new(map<int, int> x, map<int, int> y)
{
    map<int, int>::iterator it;
    cout << "order new_x\n";
    for (it = x.begin(); it != x.end(); it++)
        cout << right << setw(3) << it->first << right << setw(6) << it->second << endl;
    cout << "\norder new_y\n";
    for (it = y.begin(); it != y.end(); it++)
        cout << right << setw(3) << it->first << right << setw(6) << it->second << endl;
    cout << "\n";
}
void print_newv(vector<int> x, vector<int> y, int n)
{
    cout << "order  newv_x\n";
    for (int it = 0; it < n; it++)
        cout << right << setw(3) << it << right << setw(6) << x[it] << endl;
    cout << "\n";
    cout << "order  newv_y\n";
    for (int it = 0; it < n; it++)
        cout << right << setw(3) << it << right << setw(6) << y[it] << endl;
}
void print_nWH(int W, int H, int n)
{
    cout << "Width Height Number";
    cout << "\n  " << W + 1 << "      " << H + 1 << "     " << n << "\n\n";
}
void print_exist(vector<vector<bool>> &c_exist, int W, int H)
{
    cout << "Cube of c_exist :\n";
    for (int i = 0; i <= H; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (c_exist[i][j])
                cout << "X ";
            else
                cout << "o ";
        }
        cout << endl;
    }
    cout << endl;
}
void print_num(vector<vector<int>> &c_num, int W, int H)
{
    cout << "Cube of c_num :\n";
    for (int i = 0; i <= H + 1; i++)
    {
        for (int j = 0; j <= W + 1; j++)
        {
            cout << right << setw(2) << c_num[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void print_double(vector<vector<int>> &c_num, vector<vector<bool>> &c_exist, int W, int H)
{
    cout << endl;
    print_exist(c_exist, W, H);
    print_num(c_num, W, H);
}