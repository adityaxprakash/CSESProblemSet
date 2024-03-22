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
    int max_sum = -1e18;
    multiset<int> vals;
    for (int i = a; i <= n; i++)
    {
        if (i > b)
            vals.erase(vals.find(prefix[i - b - 1]));
        vals.insert(prefix[i - a]);
        max_sum = max(max_sum, prefix[i] - *vals.begin());
    }
    cout << max_sum;
    return 0;
}