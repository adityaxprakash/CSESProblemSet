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
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<vi> dp(n + 1, vi(m + 1, 0));
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = min(dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]), min(dp[i - 1][j], dp[i][j - 1]) + 1);
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         cout << dp[i][j];
    //     }
    //     cout << endl;
    // }
    cout << dp[n][m];
    return 0;
}