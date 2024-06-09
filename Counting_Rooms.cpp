#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i,s, n) for (int i = s; i < int(n); i++)
#define in cin
#define out cout
#define el endl
#define rn return 0 
typedef vector<int> vi; 
typedef vector<vi> vvi;

vector<pair<int, int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isValid(int r, int c, vector<vector<char> > &adj, vvi &vis)
{
    int n = adj.size();
    int m = adj[0].size();
    if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && adj[r][c] == '.')
        return true;
    return false;
}

void dfs(int r, int c, vector<vector<char> > &adj, vvi &vis)
{
    vis[r][c] = 1;
    for (auto it : direction)
    {
        int newR = r + it.first;
        int newC = c + it.second;
        if (isValid(newR, newC, adj, vis))
        {
            dfs(newR, newC, adj, vis);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char> > adj(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
        }
    }

    vvi vis(n, vi(m, 0));
    int rooms = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (adj[i][j] == '.' && !vis[i][j])
            {
                dfs(i, j, adj, vis);
                rooms++;
            }
        }
    }
    cout << rooms << endl;

    return 0;
}
