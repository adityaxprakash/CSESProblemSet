#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define send ios_base::sync_with_stdio(false);
#define help std::cin.tie(NULL);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

class dsu
{
private:
    vector<int> size;
    vector<int> root;

public:
    int components;
    int max_size;
    dsu(int n)
    {
        components = n;
        max_size = 1;
        size.resize(n, 1);
        root.resize(n);
        iota(root.begin(), root.end(), 0);
    }

    int findroot(int a)
    {
        if (a == root[a])
            return a;
        return root[a] = findroot(root[a]);
    }

    void merge(int a, int b)
    {
        a = findroot(a);
        b = findroot(b);
        if (a == b)
            return;

        if (size[a] > size[b])
            swap(a, b);
        size[b] += size[a];
        root[a] = root[b];
        max_size = max(max_size, size[b]);
        components--;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    dsu comp(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        comp.merge(a, b);
        cout << comp.components << " " << comp.max_size << "\n";
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