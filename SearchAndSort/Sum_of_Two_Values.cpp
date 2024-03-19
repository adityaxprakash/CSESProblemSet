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
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].F;
        a[i].S=i+1;
    }
    int i=0, j=n-1;
    sort(all(a));
    while(i<j)
    {
        if(a[i].F+a[j].F == x)
        {
            cout<<a[i].S<<" "<<a[j].S<<endl;
            return 0;
        }
        else if(a[i].F+a[j].F< x)
        {
            i++;
        }
        else 
        {
            j--;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}