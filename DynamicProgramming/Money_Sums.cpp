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
    int n;
    cin >> n;
    int lim = 1e5;
    vi coins(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> coins[i];
    vector<vector<bool>> dp(n + 1, vector<bool>(1 + lim, 0));
    int ans = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= lim; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= coins[i])
                dp[i][j] = (dp[i - 1][j - coins[i]]) || (dp[i][j]);
            if (i == n)
                ans += dp[i][j];
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= lim; i++)
    {
        if (dp[n][i])
            cout << i << " ";
    }
    return 0;
}