#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int sum_d=0;
    vi a(n);
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>a[i]>>d;
        sum_d+=d;
    }
    sort(all(a));
    int curr_time=0;
    for(int i=0;i<n;i++)
    {
        curr_time+=a[i];
        sum_d-=curr_time;
    }
    cout<<sum_d;
    return 0;
}