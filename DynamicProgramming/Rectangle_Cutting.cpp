#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    int a, b;
    cin >> a >> b;
    vector<vi> dp(a + 1, vi(b + 1, 1e15));
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
                continue;
            }
            for (int k = 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - k] + dp[i][k]);
            }
            for (int k = 1; k < i; k++)
            {
                dp[i][j] = min(dp[i][j], 1 + dp[i - k][j] + dp[k][j]);
            }
        }
    }
    cout << dp[a][b];

    return 0;
}