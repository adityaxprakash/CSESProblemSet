#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

bool visited[1000][1000] = {0};
vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
int n, m;
void dfs(int x, int y)
{
    visited[x][y] = 1;
    for (auto dir : directions)
    {
        int xnew = x + dir.F;
        int ynew = y + dir.S;
        if (xnew < n && xnew >= 0 && ynew < m && ynew >= 0 && !visited[xnew][ynew])
            dfs(xnew, ynew);
    }
    return;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string floor;
        cin >> floor;
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = (floor[j] == '#');
        }
    }
    int num_rooms = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                dfs(i, j);
                num_rooms++;
            }
        }
    }
    cout << num_rooms;
    return 0;
}