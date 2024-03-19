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
    vector<pair<int, int>> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i].F;
        x[i].S = i + 1;
    }
    sort(all(x));
    int rounds = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (x[i].S >= x[i + 1].S)
            rounds++;
    }
    cout << rounds;
    return 0;
}