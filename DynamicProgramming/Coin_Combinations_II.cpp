#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
const int mod = 1e9 + 7;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    int c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    int dp[x+1]={0};
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = c[i]; j <= x; j++)
        {
            dp[j] += dp[j - c[i]];
            dp[j] %= mod;
        }
    }
    cout << dp[x];
    return 0;
}