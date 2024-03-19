#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
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
    int n, k;
    cin >> n >> k;
    ordered_set kids;
    for (int i = 1; i <= n; i++)
        kids.insert(i);
    int kid_idx = k;
    while (kids.size() > 0)
    {
        kid_idx = kid_idx % kids.size();
        auto it = kids.find_by_order(kid_idx);
        cout << *it << " ";
        kids.erase(it);
        kid_idx += k;
    }
    return 0;
}
