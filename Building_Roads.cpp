//dfs
#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define forn(i, s, n) for (int i = s; i < int(n); i++)
#define in cin
#define out cout
#define el endl
#define rn return 0

typedef vector<int> vi;
typedef vector<vi> vvi;

void dfs(int u, vvi &adj, vi &vis)
{
    vis[u] = 1;
    for (auto it : adj[u])
    {
        if (!vis[it])
            dfs(it, adj, vis);
    }
}

int main()
{
    int n, m;
    in >> n >> m;
    vvi adj(n + 1); // Adjacency list, vertices are 1-based indexing
    vi vis(n + 1, 0);
    int ans = 0;
    vi res;

    forn(i, 0, m)
    {
        int u, v;
        in >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    forn(i, 1, n + 1)
    {
        if (!vis[i])
        {
            ans++;
            dfs(i, adj, vis);
            res.push_back(i);
        }
    }

    out << ans - 1 << el;

    if (ans > 1)
    {
        int u = res[0];
        for (auto it = 1; it < ans; it++)
        {
            int v = res[it];
            out << u << " " << v << el;
            u = v;
        }
    }

    rn;
}
