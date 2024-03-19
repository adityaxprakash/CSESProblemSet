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
    int n;
    cin >> n;
    vi k(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> k[i];
    int start = 1;
    int end = 1;
    map<int, int> lastseen;
    int longest_sub = 1;
    while (end <= n)
    {
        if (lastseen[k[end]] >= start)
        {
            start = lastseen[k[end]] + 1;
        }
        lastseen[k[end]] = end;
        longest_sub = max(longest_sub, end - start + 1);
        end++;
    }
    cout << longest_sub;
    return 0;
}