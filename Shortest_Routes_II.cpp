//floyd warshal(dp)-->all source to all nodes

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i, s, n) for (int i = s; i < int(n); i++)
#define in cin
#define out cout
#define el endl
#define rn return 0
typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    in >> n >> m >> q;

    vector<vector<ll> > adj(n + 1, vector<ll>(n + 1, LONG_MAX));

    // Initialize self-loops to 0
    for (int i = 1; i <= n; i++)
    {
        adj[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        ll u, v, x;
        in >> u >> v >> x;
        adj[u][v] = adj[v][u] = min(adj[u][v], x);
    }

    // Floyd-Warshall Algorithm
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] < LONG_MAX && adj[k][j] < LONG_MAX)
                {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    // Process queries
    while (q--)
    {
        int u, v;
        in >> u >> v;
        if (adj[u][v] >= LONG_MAX)
        {
            out << -1 << el;
        }
        else
        {
            out << adj[u][v] << el;
        }
    }

    return 0;
}
