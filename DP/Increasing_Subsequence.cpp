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
    vi x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    vi dp(n + 1, 1e10);
    dp[0] = -1e10;
    for (int i = 0; i < n; i++)
    {
        int l = upper_bound(all(dp), x[i]) - dp.begin();
        if (x[i] > dp[l - 1])
            dp[l] = x[i];
    }
    for (int i = n; i >= 1; i--)
    {
        if (dp[i] < 1e10)
        {
            cout << i;
            break;
        }
    }
    return 0;
}