#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

vector<string> generate_all(int len)
{
    if (len == 1)
        return {"0", "1"};
    vector<string> prev = generate_all(len - 1);
    vector<string> curr;
    for (int i = 0; i < 1; i++)
    {
        for (auto st : prev)
        {
            curr.pb(st + (char)(i + '0'));
        }
    }
    return curr;
}

bool matched(string &row)
{
    int n = row.size();
    bool parity = 0;
    for (int i = 0; i < n; i++)
    {
        if ((parity == 1 && row[i] != '0') || (parity == 0 && row[i] == '0'))
            return false;
        if (row[i] == '3' || row[i] == '2')
            continue;
        parity = !parity;
    }
    return !parity;
}

bool valid_last(string &row)
{
    int n = row.size();
    if (!matched(row))
        return false;
    for (int i = 0; i < n; i++)
    {
        if (row[i] == '2')
            return false;
    }
    return true;
}

bool valid_begin(string &row)
{
    int n = row.size();
    // if (!matched(row))
    //     return false;
    for (int i = 0; i < n; i++)
    {
        if (row[i] == '0')
            return false;
    }
    return true;
}

bool valid(string &prev, string &curr)
{
    int n = prev.size();
    if (!matched(prev) || !matched(curr))
        return false;
    for (int i = 0; i < n; i++)
    {
        if ((prev[i] == '2' && curr[i] != '3') || (prev[i] != '2' && curr[i] == '3'))
        {
            return false;
        }
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> m >> n;
    int mod = 1e9 + 7;
    vector<string> patterns = generate_all(m);
    int sz = patterns.size();
    vector<vi> dp(n + 1, vi(sz, 0));
    if (n == 1)
    {
        for (int j = 0; j < sz; j++)
        {
            if (!valid_begin(patterns[j]) || !valid_last(patterns[j]))
                continue;
            dp[1][j]++;
        }
    }
    else
    {
        for (int j = 0; j < sz; j++)
        {
            if (!valid_begin(patterns[j]))
                continue;
            dp[1][j]++;
        }
        for (int i = 2; i <= n - 1; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                for (int k = 0; k < sz; k++)
                {
                    if (valid(patterns[k], patterns[j]))
                    {
                        dp[i][j] += dp[i - 1][k];
                    }
                    dp[i][j] %= mod;
                }
            }
        }
        for (int j = 0; j < sz; j++)
        {
            if (!valid_last(patterns[j]))
                continue;
            for (int k = 0; k < sz; k++)
            {
                if (valid(patterns[k], patterns[j]))
                {
                    dp[n][j] += dp[n - 1][k];
                }
                dp[n][j] %= mod;
            }
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<sz;j++)
    //     {
    //         if(i==0)
    //             cout<<patterns[j]<<" ";
    //         else
    //             cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int tilings = 0;
    for (int i = 0; i < sz; i++)
    {
        tilings += dp[n][i];
        tilings %= mod;
    }

    cout << tilings;

    return 0;
}