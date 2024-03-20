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
    map<int, set<pair<int, int>>> hash;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int targ = x - (a[i].F + a[j].F);
            if (hash[targ].size() > 0)
            {
                auto it = hash[targ].lower_bound({j, j});
                if(it == hash[targ].begin())
                {
                    continue;
                }
                pair<int,int> ps=*it;
                int i1 =a[ps.F].S;
                int i2 =a[ps.S].S;
                cout << i1 << " " << i2 << " " << a[i].S << " " << a[j].S;
                return 0;
            }
            hash[a[i].F + a[j].F].insert({i, j});
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}