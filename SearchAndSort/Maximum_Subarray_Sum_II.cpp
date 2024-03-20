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
    int n, a, b;
    cin >> n >> a >> b;
    vi x(n);
    vi prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        prefix[i + 1] = prefix[i] + x[i];
    }
    int l = 1;
    int r = a;
    int maxSum = -1e18;
    while (r <= n)
    {
        maxSum=max(maxSum,prefix[r]-prefix[l-1]);
        
    }
    cout << maxSum;
    return 0;
}