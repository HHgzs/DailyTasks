#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int N = 5010;
int x[N], y[N], sum[N][N];
struct st1
{
    int x, pos;
};
struct st2
{
    int y, pos;
};
st1 dx[N];
st2 dy[N];
bool cmp1(st1 p, st1 q) { return p.x < q.x; }
bool cmp2(st2 p, st2 q) { return p.y < q.y; }
int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> dx[i].x >> dy[i].y;
        dx[i].pos = i, dy[i].pos = i;
    }
    sort(dx, dx + n, cmp1);
    sort(dy, dy + n, cmp2);
    x[dx[0].pos] = 1;
    y[dy[0].pos] = 1;
    int W = 1, H = 1;
    for (int i = 1; i < n; i++)
    {
        if (dx[i].x > dx[i - 1].x)
            x[dx[i].pos] = ++W;
        else
            x[dx[i].pos] = W;
    }
    for (int i = 1; i < n; i++)
    {
        if (dy[i].y > dy[i - 1].y)
            y[dy[i].pos] = ++H;
        else
            y[dy[i].pos] = H;
    }
    for (int i = 0; i < n; i++)
        sum[x[i]][y[i]] = 1;

    cout << "Cube of exist :\n";
    for (int i = 0; i <= H; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (sum[i][j])
                cout << "X ";
            else
                cout << "o ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }

    cout << "Cube of num :\n";
    for (int i = 0; i <= H; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            cout << right << setw(2) << sum[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    while (m--)
    {
        int c1, c2;
        cin >> c1 >> c2;
        int ans = 0;
        int x1 = x[c1], y1 = y[c1];
        int x2 = x[c2], y2 = y[c2];
        ans = sum[y2][x2] - sum[y2][x1 - 1] - sum[y1 - 1][x2] + sum[y1][x1];
        cout << ans << endl;
    }
}
