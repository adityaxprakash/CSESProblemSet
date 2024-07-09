#include <bits/stdc++.h>
using namespace std;
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
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> prefix;
    prefix[0] = 1;
    int num_subarray = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        num_subarray += prefix[sum - x];
        prefix[sum]++;
    }
    cout << num_subarray;
    return 0;
}