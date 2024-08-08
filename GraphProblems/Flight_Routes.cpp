#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define send ios_base::sync_with_stdio(false);
#define help std::cin.tie(NULL);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    priority_queue<ll> dists[n];
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        adj[a].push_back({b, c});
    }

    priority_queue<pair<ll, int>> pq;
    dists[0].push(0);
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        d = -d;
        if (d > dists[u].top())
            continue;
        for (auto [v, w] : adj[u])
        {
            ll alt = d + w;
            if (dists[v].size() < k)
            {
                dists[v].push(alt);
                pq.push({-alt, v});
            }
            else if (dists[v].size() == k && dists[v].top() > alt)
            {
                dists[v].pop();
                dists[v].push(alt);
                pq.push({-alt, v});
            }
        }
    }

    vector<ll> ans;
    while (!dists[n - 1].empty())
    {
        ans.push_back(dists[n - 1].top());
        dists[n - 1].pop();
    }
    reverse(ans.begin(), ans.end());
    for (auto a : ans)
        cout << a << " ";
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