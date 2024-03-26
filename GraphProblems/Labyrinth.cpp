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
char labyrinth[1000][1000];
pair<int, int> pointA;
pair<int, int> pointB;
pair<int, int> par[1000][1000];

queue<pair<int, int>> q;
bool bfs()
{
    while (!q.empty())
    {
        int x = q.front().F;
        int y = q.front().S;
        if (pointB.F == x && pointB.S == y)
            return true;
        q.pop();
        for (auto dir : directions)
        {
            int xnew = x + dir.F;
            int ynew = y + dir.S;
            if (xnew < n && xnew >= 0 && ynew < m && ynew >= 0 && !visited[xnew][ynew])
            {
                q.push({xnew, ynew});
                visited[xnew][ynew] = 1;
                par[xnew][ynew] = {x, y};
            }
        }
    }
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 1000; ++i)
    {
        for (int j = 0; j < 1000; ++j)
        {
            par[i][j] = {-1, -1};
        }
    }
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            labyrinth[i][j] = s[j];
            if (labyrinth[i][j] == 'A')
                pointA = {i, j};
            if (labyrinth[i][j] == 'B')
                pointB = {i, j};
            visited[i][j] = (labyrinth[i][j] == '#');
        }
    }
    q.push(pointA);
    visited[pointA.F][pointA.S] = 1;
    bool ans = bfs();
    if (!ans)
    {
        cout << "NO";
        return 0;
    }
    string s;
    while (par[pointB.F][pointB.S].F != -1)
    {
        int x = pointB.F;
        int y = pointB.S;
        int xpar = par[x][y].F;
        int ypar = par[x][y].S;
        if (xpar == x + 1)
        {
            s += 'U';
        }
        else if (xpar == x - 1)
        {
            s += 'D';
        }
        else if (ypar == y + 1)
        {
            s += 'L';
        }
        else
        {
            s += 'R';
        }
        pointB = par[x][y];
    }
    reverse(all(s));
    cout << "YES\n"
         << s.size() << "\n"
         << s;
    return 0;
}