#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5010;
int c1, c2, n, x[N], y[N], sum[N][N];
int x01, x02, y01, y02, m;
struct st
{
    int xy, pos;
};
st dx[N], dy[N];
bool cmp(st p, st q) { return p.xy < q.xy; }
int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> dx[i].xy >> dy[i].xy;
        dx[i].pos = i, dy[i].pos = i;
    }
    sort(dx, dx + n, cmp);
    sort(dy, dy + n, cmp);
    x[dx[0].pos] = 1;
    y[dy[0].pos] = 1;
    int W = 1, H = 1;
    for (int i = 1; i < n; i++)
    {
        if (dx[i].xy > dx[i - 1].xy)
            x[dx[i].pos] = ++W;
        else
            x[dx[i].pos] = W;
    }
    for (int i = 1; i < n; i++)
    {
        if (dy[i].xy > dy[i - 1].xy)
            y[dy[i].pos] = ++H;
        else
            y[dy[i].pos] = H;
    }
    for (int i = 0; i < n; i++)
        sum[y[i]][x[i]] = 1;

    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];

    while (m--)
    {
        cin >> c1 >> c2;
        x01 = x[c1];
        y01 = y[c1];
        x02 = x[c2];
        y02 = y[c2];
        if (x01 > x02)
            swap(x01, x02);
        if (y01 > y02)
            swap(y01, y02);
        cout << sum[y02][x02] - sum[y02][x01 - 1] - sum[y01 - 1][x02] + sum[y01 - 1][x01 - 1] << '\n';
    }
    return 0;
}
