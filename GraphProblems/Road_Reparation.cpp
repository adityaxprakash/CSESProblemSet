#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define send ios_base::sync_with_stdio(false);
#define help std::cin.tie(NULL);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

struct Road
{
    int to;
    int cost;
    bool operator>(const Road &other) const { return cost > other.cost; }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<Road> roads[n];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        roads[a].push_back({b, c});
        roads[b].push_back({a, c});
    }
    
    vector<bool> visited(n, false);
    priority_queue<Road, vector<Road>, greater<Road>> pq;
    pq.push({0, 0});
    int numVisited = 0;
    ll minCost = 0;
    while (!pq.empty())
    {
        auto [u, w] = pq.top();
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        numVisited++;
        minCost += w;
        for (auto [v, cost] : roads[u])
        {
            if (!visited[v])
                pq.push({v, cost});
        }
    }

    if(numVisited != n)
        cout << "IMPOSSIBLE";
    else 
        cout << minCost;

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