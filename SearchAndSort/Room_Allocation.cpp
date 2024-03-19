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
    vector<vi> times(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        times[i] = {a, b, i};
    }
    sort(all(times));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> in_use;
    vi room_used(n);
    int k = 1;
    int available = 2;
    in_use.push({times[0][1], 1});
    room_used[times[0][2]]=1;
    for (int i = 1; i < n; i++)
    {
        int arrival = times[i][0];
        int depart = times[i][1];
        int idx = times[i][2];
        int allotted;
        if (!in_use.empty() && in_use.top().F < arrival)
        {
            allotted = in_use.top().S;
            in_use.pop();
        }
        else
        {
            allotted=available++;
        }
        room_used[idx]=allotted;
        k = max(k,allotted);
        in_use.push({depart, allotted});
    }
    cout << k << "\n";
    for (int i = 0; i < room_used.size(); i++)
        cout << room_used[i] << " ";
    return 0;
}