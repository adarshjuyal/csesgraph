#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

#define ll long long
#define forn(i, s, n) for (int i = s; i < int(n); i++)
#define in cin
#define out cout
#define el endl
#define rn return 0

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m;
vvi grid;
vector<pair<int, int>> monster;
map<pair<int, int>, pair<int, int>> mp;
pair<int, int> si, se;
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool isValid(int r, int c, int timer)
{
    if (r < 0 || r >= n || c < 0 || c >= m)
        return false;
    if (grid[r][c] <= timer)
        return false;
    return true;
}

bool isPossible(int r, int c, int timer)
{
    if (!isValid(r, c, timer))
        return false;
    if (r == 0 || c == 0 || r == n - 1 || c == m - 1)
        return true;
    return false;
}

void processMonster()
{
    queue<pair<pair<int, int>, int>> q;
    for (auto it : monster)
    {
        q.push({it, 0});
    }
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int timer = q.front().second;
        timer++;
        q.pop();
        for (auto m : moves)
        {
            int nrow = r + m.first;
            int ncol = c + m.second;
            if (isValid(nrow, ncol, timer))
            {
                grid[nrow][ncol] = timer;
                q.push({{nrow, ncol}, timer});
            }
        }
    }
}

bool tryEscape()
{
    queue<pair<pair<int, int>, int>> q;
    q.push({si, 0});
    mp[si] = {-1, -1};
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int timer = q.front().second;
        timer++;
        q.pop();
        for (auto m : moves)
        {
            int nrow = m.first + r;
            int ncol = m.second + c;
            if (isPossible(nrow, ncol, timer))
            {
                mp[{nrow, ncol}] = {r, c};
                se = {nrow, ncol};
                return true;
            }
            if (isValid(nrow, ncol, timer))
            {
                grid[nrow][ncol] = timer;
                mp[{nrow, ncol}] = {r, c};
                q.push({{nrow, ncol}, timer});
            }
        }
    }
    return false;
}

int main()
{
    in >> n >> m;
    grid.resize(n, vi(m, INT_MAX));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            in >> ch;
            if (ch == '#')
            {
                grid[i][j] = 0;
            }
            else if (ch == 'A')
            {
                grid[i][j] = 0;
                si = {i, j};
            }
            else if (ch == 'M')
            {
                grid[i][j] = 0;
                monster.push_back({i, j});
            }
        }
    }

    if (si.first == 0 || si.second == 0 || si.first == n - 1 || si.second == m - 1)
    {
        out << "YES" << el << 0 << el;
        rn;
    }

    processMonster();

    if (!tryEscape())
    {
        out << "NO" << el;
        rn;
    }

    out << "YES" << el;
    pair<int, int> tmp = se;
    pair<int, int> tmp1 = mp[se];
    pair<int, int> ed = {-1, -1};
    vector<char> ans;
    while (tmp1 != ed)
    {
        if ((tmp.second - tmp1.second) == 1 && (tmp.first - tmp1.first) == 0)
        {
            ans.push_back('R');
        }
        if ((tmp.second - tmp1.second) == -1 && (tmp.first - tmp1.first) == 0)
        {
            ans.push_back('L');
        }
        if ((tmp.second - tmp1.second) == 0 && (tmp.first - tmp1.first) == 1)
        {
            ans.push_back('D');
        }
        if ((tmp.second - tmp1.second) == 0 && (tmp.first - tmp1.first) == -1)
        {
            ans.push_back('U');
        }
        tmp = mp[tmp];
        tmp1 = mp[tmp];
    }
    reverse(ans.begin(), ans.end());
    out << ans.size() << el;
    for (auto c : ans)
    {
        out << c;
    }

    return 0;
}
