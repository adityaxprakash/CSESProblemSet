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
int cost = 0;

void add(int ele)
{
    if (low.size() == high.size())
    {
        if (ele <= *high.begin())
        {
            low.insert(ele);
            cost -= ele;
        }
        else
        {
            cost -= 2 * (*high.begin()) - ele;
            low.insert(*high.begin());
            high.erase(high.begin());
            high.insert(ele);
        }
    }
    else
    {
        if (ele < *low.rbegin())
        {
            cost -= ele - 2 * (*low.rbegin());
            low.insert(ele);
            high.insert(*low.rbegin());
            low.erase(prev(low.end()));
        }
        else
        {
            high.insert(ele);
            cost += ele;
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
            cost -= ele;
        }
        else
        {
            cost += ele - 2 * (*high.begin());
            low.erase(low.find(ele));
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    }
    else
    {
        if (low.find(ele) != low.end())
        {
            cost += ele;
            low.erase(low.find(ele));
        }
        else
        {
            cost -= ele - 2 * (*low.rbegin());
            high.erase(high.find(ele));
            high.insert(*low.rbegin());
            low.erase(prev(low.end()));
        }
    }
}
void print_cost(int k)
{
    if (k % 2 == 0)
    {
        cout << cost << " ";
    }
    else
    {
        cout << cost + *low.rbegin() << " ";
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
    vi prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        prefix[i + 1] = prefix[i] + a[i];
    }
    low.insert(a[0]);
    cost -= a[0];
    for (int i = 1; i < k; i++)
        add(a[i]);
    print_cost(k);
    for (int i = k; i < n; i++)
    {
        add(a[i]);
        remove(a[i - k]);
        print_cost(k);
    }

    return 0;
}