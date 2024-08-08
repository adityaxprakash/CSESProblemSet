#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define send ios_base::sync_with_stdio(false);
#define help std::cin.tie(NULL);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int N = 2e5 + 2;
int pathLength[N];
int nxt[N];
bool visited[N];
int steps;
queue<int> currPath;

void dfs(int u)
{
    currPath.push(u);
    if (visited[u])
    {
        steps += pathLength[u];
        return;
    }
    steps++;
    visited[u] = true;
    dfs(nxt[u]);
}

void solve()
{
    int n;
    cin >> n;
    fill(visited, visited + N, false);
    fill(pathLength, pathLength + N, 0);

    for (int i = 1; i <= n; i++)
        cin >> nxt[i];

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        steps = 0;
        dfs(i);
        int decrement = 1;
        while (!currPath.empty())
        {
            if (currPath.front() == currPath.back())
                decrement = 0;
            int u = currPath.front();
            currPath.pop();
            pathLength[u] = steps;
            steps -= decrement;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << pathLength[i] << " ";
}

int main()
{
    send help;

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}