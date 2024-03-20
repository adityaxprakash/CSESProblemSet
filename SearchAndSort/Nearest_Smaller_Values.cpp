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
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stack<int> stk;
    vi ple(n,0);
    for (int i = 0; i < n; i++)
    {
        while(!stk.empty() && a[stk.top()]>=a[i])
        {
            stk.pop();
        }
        if(!stk.empty())
            ple[i]=stk.top()+1;
        stk.push(i);
    }
    for(auto i:ple)
        cout<<i<<" ";
    return 0;
}