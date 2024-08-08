#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define send ios_base::sync_with_stdio(false);
#define help std::cin.tie(NULL);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int L = 30;

void solve()
{
    int n, q;
    cin >> n >> q;
    int up[n + 1][L];
    for (int i = 1; i <= n; i++)
    {
        cin >> up[i][0];
    }
    for (int i = 1; i < L; i++)
    {
        for (int j = 1; j <= n; j++)
            up[j][i] = up[up[j][i - 1]][i - 1];
    }
    while (q--)
    {
        int x, k;
        cin >> x >> k;
        for (int i = 0; i < L; i++)
        {
            if (k & (1 << i))
                x = up[x][i];
        }
        cout << x << "\n";
    }
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