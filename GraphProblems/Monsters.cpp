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
const int int_inf = 1e9;

const int N = 1000;
int n, m;
char grid[N][N];
vvi mdist(N, vi(N, int_inf));
vvi src_dist(N, vi(N, int_inf));
pii parent[N][N];

queue<pii> q;
pii src;
pii dest = {-1, -1};
stack<char> path;

bool check(int x, int y, vvi &dist)
{
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && dist[x][y] == int_inf;
}

void recurse(int x, int y, vvi &dist)
{
    if (check(x - 1, y, dist))
    {
        q.push({x - 1, y});
        parent[x - 1][y] = {x, y};
        dist[x - 1][y] = dist[x][y] + 1;
    }
    if (check(x + 1, y, dist))
    {
        q.push({x + 1, y});
        parent[x + 1][y] = {x, y};
        dist[x + 1][y] = dist[x][y] + 1;
    }
    if (check(x, y - 1, dist))
    {
        q.push({x, y - 1});
        parent[x][y - 1] = {x, y};
        dist[x][y - 1] = dist[x][y] + 1;
    }
    if (check(x, y + 1, dist))
    {
        q.push({x, y + 1});
        parent[x][y + 1] = {x, y};
        dist[x][y + 1] = dist[x][y] + 1;
    }
}

bool edge(int x, int y)
{
    return x == 0 || x == n - 1 || y == 0 || y == m - 1;
}

void bfs(bool for_src)
{
    while (!q.empty())
    {
        pii top = q.front();
        q.pop();
        int x = top.f;
        int y = top.s;
        if (!for_src)
            recurse(x, y, mdist);
        else
        {
            if (edge(x, y) && src_dist[x][y] < mdist[x][y])
            {
                dest = {x, y};
                return;
            }
            recurse(x, y, src_dist);
        }
    }
}

void reconstruct(pii dest, pii src)
{
    while (dest != src)
    {
        int x = parent[dest.f][dest.s].f;
        int y = parent[dest.f][dest.s].s;
        if (x == dest.f - 1)
        {
            path.push('D');
        }
        if (x == dest.f + 1)
        {
            path.push('U');
        }
        if (y == dest.s - 1)
        {
            path.push('R');
        }
        if (y == dest.s + 1)
        {
            path.push('L');
        }
        dest = {x, y};
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'M')
            {
                q.push({i, j});
                mdist[i][j] = 0;
            }
            if (grid[i][j] == 'A')
            {
                src = {i, j};
                src_dist[i][j] = 0;
            }
        }
    }
    bfs(false);
    q.push(src);
    bfs(true);
    
    if (dest.f == -1 && dest.s == -1)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    reconstruct(dest, src);
    cout << path.size() << "\n";
    while (!path.empty())
    {
        cout << path.top();
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