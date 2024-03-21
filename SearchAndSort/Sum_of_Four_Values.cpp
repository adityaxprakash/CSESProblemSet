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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<int, pair<int, int>> hash;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int targ = x - (a[i] + a[j]);
            if (hash.find(targ) != hash.end())
            {
                int i1 = hash[targ].F + 1;
                int i2 = hash[targ].S + 1;
                cout << i1 << " " << i2 << " " << i + 1 << " " << j + 1;
                return 0;
            }
        }
        for (int j = 0; j < i; j++)
        {
            hash[a[i] + a[j]] = {i, j};
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}