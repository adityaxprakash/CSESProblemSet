
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
    vi p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    sort(all(p));
    int median = p[(n / 2)];
    int min_cost = 0;
    for (int i = 0; i < n; i++)
    {
        min_cost += abs(median - p[i]);
    }
    cout << min_cost;
    return 0;
}