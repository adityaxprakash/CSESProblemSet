#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define vvi vector<vi>
#define all(x) (x).begin(), (x).end()
const int mod = 1e9 + 7;
const ll inf = 1e18;

const int N = 1e5 + 1;
vi adj[N];
int in[N];
vi toposort;

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        in[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        toposort.pb(u);
        q.pop();
        for (auto v : adj[u])
        {
            in[v]--;
            if (in[v] == 0)
                q.push(v);
        }
    }
    if (toposort.size() != n)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    for (auto i : toposort)
        cout << i << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}