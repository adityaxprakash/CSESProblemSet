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

int n, m;
vi adj[N];
vector<bool> visited(N, 0);
int parent[N];
int src;
bool found_cycle = false;

bool dfs(int u, vector<bool> &seen)
{
    seen[u] = 1;
    for (auto v : adj[u])
    {
        if(visited[v])
            continue;
        parent[v] = u;
        if (seen[v])
        {
            src = v;
            return true;
        }
        if(dfs(v, seen))
            return true;
    }
    visited[u] = 1;
    seen[u] = 0;
    return false;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            vector<bool> seen(N, 0);
            if(dfs(i, seen))
            {
                found_cycle = true;
                break;
            }
        }
    }

    if (!found_cycle)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    stack<int> path;
    int curr = parent[src];
    path.push(src);
    while (curr != src)
    {
        path.push(curr);
        curr = parent[curr];
    }
    path.push(curr);
    cout << path.size() << "\n";
    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }
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