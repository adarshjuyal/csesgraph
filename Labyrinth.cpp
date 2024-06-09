#include <bits/stdc++.h>
#define ll long long
#define forn(i, s, n) for (int i = s; i < int(n); i++)
#define in cin
#define out cout
#define el endl
#define rn return 0
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vector<string> graph(1000);
vector<vector<char>> steps(1000, vector<char>(1000));
bool visited[1000][1000];
pair<ll, ll> start, dest;
stack<char> ans;
ll n, m;

bool isValid(ll x, ll y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] != '#' && !visited[x][y]);
}

void backtrack(ll x, ll y)
{
    if (steps[x][y] != 'X')
    {
        char ch = steps[x][y];
        ans.push(ch);
        if (ch == 'U')
            backtrack(x + 1, y);
        else if (ch == 'D')
            backtrack(x - 1, y);
        else if (ch == 'L')
            backtrack(x, y + 1);
        else if (ch == 'R')
            backtrack(x, y - 1);
    }
}

bool bfs(ll x, ll y)
{
    steps[x][y] = 'X';
    bool found = false;
    queue<pair<ll, ll>> q;
    q.push({x, y});
    while (!q.empty())
    {
        auto ele = q.front();
        x = ele.first;
        y = ele.second;
        q.pop();
        if (graph[x][y] == 'B')
        {
            found = true;
            break;
        }
        visited[x][y] = true;
        if (isValid(x - 1, y))
        {
            visited[x - 1][y] = true;
            steps[x - 1][y] = 'U';
            q.push({x - 1, y});
        }
        if (isValid(x, y + 1))
        {
            visited[x][y + 1] = true;
            steps[x][y + 1] = 'R';
            q.push({x, y + 1});
        }
        if (isValid(x + 1, y))
        {
            visited[x + 1][y] = true;
            steps[x + 1][y] = 'D';
            q.push({x + 1, y});
        }
        if (isValid(x, y - 1))
        {
            visited[x][y - 1] = true;
            steps[x][y - 1] = 'L';
            q.push({x, y - 1});
        }
    }
    if (found)
    {
        backtrack(x, y);
        return true;
    }
    else
        return false;
}

int main()
{
    in >> n >> m;
    forn(i, 0, n)
    {
        in >> graph[i];
    }

    forn(i, 0, n)
    {
        forn(j, 0, m)
        {
            if (graph[i][j] == 'A')
                start = {i, j};
            else if (graph[i][j] == 'B')
                dest = {i, j};
        }
    }

    if (bfs(start.first, start.second))
    {
        out << "YES" << el;
        out << ans.size() << el;
        while (!ans.empty())
        {
            out << ans.top();
            ans.pop();
        }
        out << el;
    }
    else
    {
        out << "NO" << el;
    }

    rn;
}
