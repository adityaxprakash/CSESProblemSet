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
    int l = 0, r = 0;
    int running_sum = 0;
    int num_subarray = 0;
    while (r < n && l <= r)
    {
        running_sum+=a[r];
        while (running_sum > x)
        {
            running_sum -= a[l];
            l++;
        }
        if(running_sum==x)
        {
            num_subarray++;
            running_sum-=a[l];
            l++;
        }
        r++;
    }
    cout << num_subarray;
    return 0;
}