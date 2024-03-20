#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

int f(vi &a, int m)
{
    int n = a.size();
    int num = 0;
    int temp = 0;
    int i = 0;
    while (i < n)
    {
        while (i < n && temp + a[i] <= m)
        {
            temp += a[i];
            i++;
        }
        num++;
        if (i >= n)
            return num;
        if (a[i] > m)
        {
            return 1e10;
        }
        temp = 0;
    }
    return num;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 1;
    int r = 1e18;
    int min_sum = 1e18;
    while (l <= r)
    {
        int m = (l + r) / 2;
        int num = f(a, m);
        if (num <= k)
        {
            min_sum = min(min_sum, m);
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << min_sum<<endl;
    return 0;
}