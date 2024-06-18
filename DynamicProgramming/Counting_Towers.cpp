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
    int t;
    cin >> t;
    int lim = 1e6;
    int mod = 1e9 + 7;
    vi dp(lim + 1);
    int running_sum = 1;
    for (int i = 1; i <= lim; i++)
    {
        dp[i] = 2 * running_sum;
        dp[i] %= mod;
        running_sum += dp[i];
        running_sum %= mod;
    }
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}