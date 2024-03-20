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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> times(n);
    for (int i = 0; i < n; i++)
    {
        cin >> times[i].S >> times[i].F;
    }
    sort(all(times));
    multiset<int> watching;
    for (int i = 1; i <= k; i++)
        watching.insert(1);
    int movies_watched = 0;
    for (int i = 0; i < n; i++)
    {
        int start = times[i].S;
        int end = times[i].F;
        auto it = watching.upper_bound(start);
        if (it == watching.begin())
        {
            continue;
        }
        watching.erase(prev(it));
        watching.insert(end);
        movies_watched++;
    }
    cout << movies_watched;

    return 0;
}