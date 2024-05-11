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

void solve()
{
    int n, x;
    cin >> n >> x;
    vi w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    vpii best(1 << n, {n + 1, 0});
    best[0] = {1, 0};

    for (int s = 0; s < (1 << n); s++)
    {
        for (int p = 0; p < n; p++)
        {
            pair<int, int> alt = best[s ^ (1 << p)];
            if (alt.s + w[p] <= x)
            {
                alt.s += w[p];
            }
            else
            {
                alt.f++;
                alt.s = w[p];
            }
            best[s] = min(best[s], alt);
        }
    }

    cout << best[(1 << n) - 1].f;
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