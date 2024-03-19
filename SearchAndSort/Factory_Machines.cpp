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
    int n, t;
    cin >> n >> t;
    vi k(n);
    for (int i = 0; i < n; i++)
        cin >> k[i];
    int l = 1;
    int h = 1e18;
    int min_time = 1e18;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        int possible = 0;
        for (int i = 0; i < n; i++)
        {
            possible += (mid / k[i]);
            if(possible>t)
                break;
        }
        if (possible >= t)
        {
            min_time = min(min_time, mid);
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << min_time;
    return 0;
}