#include <bits/stdc++.h>
#define LL long long
#define pa pair<int, int>
#define ls k << 1
#define rs k << 1 | 1
#define inf 0x3f3f3f3f
using namespace std;
const int N = 1100;
const int M = 2000100;
const int mod = 1e9;
int n, x[N], y[N], sum[N][N];
struct Node1
{
    int x, pos;
} dx[N];
struct Node2
{
    int y, pos;
} dy[N];
bool cmp1(Node1 p, Node1 q) { return p.x < q.x; }
bool cmp2(Node2 p, Node2 q) { return p.y < q.y; }
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> dx[i].x >> dy[i].y;
        dx[i].pos = i, dy[i].pos = i;
    }
    sort(dx + 1, dx + n + 1, cmp1);
    sort(dy + 1, dy + n + 1, cmp2);
    for (int i = 1; i <= n; i++)
    {
        x[dx[i].pos] = i;
        y[dy[i].pos] = i;
    }
    for (int i = 1; i <= n; i++)
        sum[x[i]][y[i]] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
    int ans = 2e9;
    for (int i = 1; i <= n; i++)
    { // Ã¶¾Ùx
        for (int j = 1; j <= n; j++)
        { // Ã¶¾Ùy
            int mmax = 0;
            mmax = max(max(sum[i][n] - sum[i][j], sum[i][j]), mmax);
            mmax = max(max(sum[n][j] - sum[i][j], sum[n][n] - sum[i][n] - sum[n][j] + sum[i][j]), mmax);
            ans = min(mmax, ans);
        }
    }
    cout << ans << endl;
    return 0;
}
