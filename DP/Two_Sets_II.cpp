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
    int n;
    cin >> n;
    int mod = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(n * n, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i * i; j++)
        {
            if (j >= i)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i];
            else
                dp[i][j] = dp[i - 1][j];
            dp[i][j] %= mod;
        }
    }
    int target = n * (n + 1) / 2;
    if (target % 2 == 1)
        cout << 0;
    else
    {
        target /= 2;
        cout << dp[n][target];
    }
    return 0;
}