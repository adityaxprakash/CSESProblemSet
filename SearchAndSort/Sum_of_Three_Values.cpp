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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].F;
        a[i].S = i + 1;
    }
    sort(all(a));
    for (int i = 0; i < n; i++)
    {
        int target = x - a[i].F;
        int l = 0;
        int r = n - 1;
        while (l < r)
        {
            if (l == i)
            {
                l++;
                continue;
            }
            if (r == i)
            {
                r--;
                continue;
            }
            int possiblesum = a[l].F + a[r].F;
            if (possiblesum < target)
            {
                l++;
            }
            else if (possiblesum > target)
            {
                r--;
            }
            else
            {
                cout << a[l].S << " " << a[r].S << " " << a[i].S;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}