#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define print(a)                             \
    for (int i = 0; i < (a).size() - 1; i++) \
        cout << (a)[i] << " ";               \
    cout << (a)[(a).size() - 1] << endl;
class dsu
{
public:
    vi parent, size;

    dsu(int n)
    {
        size = vi(n, 1);
        for (int i = 0; i < n; i++)
            parent.pb(i);
    }
    void make_set(int v)
    {
        parent[v] = v;
        size[v] = 1;
    }

    void merge(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int find(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<vi> ranges(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ranges[i] = {a, -b, i};
    }
    sort(all(ranges));
    vi is_contained(n, 0);
    vi contains(n, 0);
    int maxr = 0;
    for (int i = 0; i < n; i++)
    {
        int curr_start = ranges[i][0];
        int curr_end = -ranges[i][1];
        int idx = ranges[i][2];
        if (maxr >= curr_end)
        {
            is_contained[idx] = 1;
        }
        maxr = max(maxr, curr_end);
    }
    int minr = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        int curr_start = ranges[i][0];
        int curr_end = -ranges[i][1];
        int idx = ranges[i][2];
        if (minr <= curr_end)
        {
            contains[idx] = 1;
        }
        minr = min(minr, curr_end);
    }
    print(contains);
    print(is_contained);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}