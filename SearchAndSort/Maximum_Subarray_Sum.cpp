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
    cin>>n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vi dp(n + 1, 0);
    int max_sum = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(a[i - 1], dp[i - 1] + a[i - 1]);
        max_sum = max(max_sum, dp[i]);
    }
    cout << max_sum;
    return 0;
}