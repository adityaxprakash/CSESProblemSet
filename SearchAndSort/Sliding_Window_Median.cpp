#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

multiset<int> low;
multiset<int> high;

void add(int ele)
{
    if (low.size() == high.size())
    {
        if (ele <= *high.begin())
        {
            low.insert(ele);
        }
        else
        {
            low.insert(*high.begin());
            high.erase(high.begin());
            high.insert(ele);
        }
    }
    else
    {
        if (ele < *low.rbegin())
        {
            low.insert(ele);
            high.insert(*low.rbegin());
            low.erase(prev(low.end()));
        }
        else
        {
            high.insert(ele);
        }
    }
}

void remove(int ele)
{
    if (low.size() == high.size())
    {
        if (high.find(ele) != high.end())
        {
            high.erase(high.find(ele));
        }
        else
        {
            low.erase(low.find(ele));
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    }
    else
    {
        if (low.find(ele) != low.end())
        {
            low.erase(low.find(ele));
        }
        else
        {
            high.erase(high.find(ele));
            high.insert(*low.rbegin());
            low.erase(prev(low.end()));
        }
    }
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
        cin >> a[i];
    low.insert(a[0]);
    for (int i = 1; i < k; i++)
        add(a[i]);
    cout << *low.rbegin() << " ";
    for (int i = k; i < n; i++)
    {

        add(a[i]);
        remove(a[i - k]);
        cout << *low.rbegin() << " ";
    }

    return 0;
}   