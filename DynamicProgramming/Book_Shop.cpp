#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    vi cost(n);
    vi weight(n);
    for (auto &i : cost)
        cin >> i;
    for (auto &i : weight)
        cin >> i;
    vector<vi> dp(n + 1, vi(x + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (cost[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i - 1]] + weight[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][x];
    return 0;
}