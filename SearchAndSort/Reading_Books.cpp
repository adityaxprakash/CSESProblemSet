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
    int sum = 0;
    int maxt=0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        sum += t;
        maxt=max(maxt,t);
    }
    sum-=maxt;
    if (sum < maxt)
    {
        cout << 2 * maxt;
    }
    else
    {
        cout << sum + maxt;
    }
    return 0;
}