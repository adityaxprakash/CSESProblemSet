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
    int n, m;
    int mod = 1e9 + 7;
    cin >> n >> m;
    vi array(n);
    for (auto &i : array)
        cin >> i;
    vector<vi> dp(n + 1, vi(m + 2, 0));
    for (int i = 1; i <= m; i++)
        dp[1][i] = (array[0] == 0 || array[0] == i);
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (array[i - 1] == 0 || array[i - 1] == j)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1])%mod;
            }
        }
    }
    int pos = 0;
    for (int i = 1; i <= m; i++)
        pos =(pos+ dp[n][i])%mod;
    cout << pos;
    return 0;
}