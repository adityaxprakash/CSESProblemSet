#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll long long
#define send ios_base::sync_with_stdio(false);
#define help cin.tie(NULL);
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define vvi vector<vi>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
const int mod = 1e9 + 7;
const ll inf = 1e18;

const int N = 2e5 + 10;
int arr[N];
ll prefix[N];

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i];
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << endl;
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