#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

const int lim = 2e5 + 1;
int subordinates[lim];
int n;
vi adj[lim];

int dfs(int u)
{
    subordinates[u] = 0;
    for (auto v : adj[u])
    {
        subordinates[u] += dfs(v);
    }
    return 1 + subordinates[u];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int ai;
        cin >> ai;
        adj[ai].pb(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << subordinates[i] << " ";

    return 0;
}