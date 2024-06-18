#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

bool compare(const vi &a, const vi &b)
{
    return a[0] < b[0];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vi> projects(n + 1, vi(3));
    vi max_dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> projects[i][1] >> projects[i][0] >> projects[i][2];
    }
    projects[0] = {0, 0, 0};
    sort(all(projects));
    vi dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int curr_start = projects[i][1];
        int curr_prize = projects[i][2];
        int mx = lower_bound(projects.begin(), projects.begin() + i, vi{curr_start, 0, 0}, compare) - projects.begin() - 1;
        dp[i] = max_dp[mx] + curr_prize;
        max_dp[i] = max(max_dp[i - 1], dp[i]);
    }
    cout << max_dp[n];
    return 0;
}