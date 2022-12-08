#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5010;
int x[N], y[N], sum[N][N];
struct st1
{
    long long x;
    int pos;
} dx[N];
struct st2
{
    long long y;
    int pos;
} dy[N];
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
        sum[y[i]][x[i]] = 1;

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
    while (m--)
    {
        int c1, c2;
        cin >> c1 >> c2;
        int ans = 0;
        int x1 = x[c1], y1 = y[c1];
        int x2 = x[c2], y2 = y[c2];
        ans = sum[y2][x2] - sum[y2][x1 - 1] - sum[y1 - 1][x2] + sum[y1-1][x1-1];
        cout << ans << endl;
    }
}
