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
    vi a(n + 1);
    vi prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    vector<vi> dp(n + 1, vi(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            dp[i][j] = max(prefix[j + i - 1] - prefix[j] - dp[i - 1][j + 1] + a[j], prefix[j + i - 2] - prefix[j - 1] - dp[i - 1][j] + a[j + i - 1]);
        }
    }
    cout<<dp[n][1];
    return 0;
}