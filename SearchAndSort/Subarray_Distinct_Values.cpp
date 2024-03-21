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
    int n, k;
    cin >> n >> k;
    vi x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    int l = 0;
    map<int, int> freq;
    int unique = 0;
    int r = 0;
    int num_subarray = 0;
    while (l < n)
    {
        while (r < n && unique + (freq[x[r]] == 0) <= k)
        {
            unique += (freq[x[r]] == 0);
            freq[x[r]]++;
            r++;
        }
        num_subarray += r - l;
        freq[x[l]]--;
        unique-=(freq[x[l]]==0);
        l++;
    }
    cout << num_subarray;
    return 0;
}