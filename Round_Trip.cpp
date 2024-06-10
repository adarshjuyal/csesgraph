#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
#define ll long long
#define forn(i, s, n) for (int i = s; i < int(n); i++)
#define in cin
#define out cout
#define el endl
#define rn return 0
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adj;
vi path, vis;
int sv = -1, ev = -1;

bool dfs(int u, int par)
{
    vis[u] = 1;
    path[u] = par;
    for (auto v : adj[u])
    {
        if (v == par)
            continue; // Skip the parent vertex
        if (vis[v])
        {
            sv = v;
            ev = u;
            return true;
        }
        if (!vis[v])
        {
            if (dfs(v, u))
                return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    in >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1, 0);
    path.resize(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        in >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1))
            {
                // Cycle found
                int tv = ev;
                vector<int> ans;
                ans.push_back(ev);
                while (tv != sv)
                {
                    ans.push_back(path[tv]);
                    tv = path[tv];
                }
                ans.push_back(ev);
                cout << ans.size() << endl;
                for (auto c : ans)
                {
                    cout << c << " ";
                }
                rn;
            }
        }
    }

    out << "IMPOSSIBLE" << el;
    rn;
}
// #include<iostream>
// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// #define int long long int

// int n, m;
// int sv, ev;
// vector<vector<int> > g;
// vector<int> vis;
// vector<int> parent;

// bool dfs(int u, int p)
// {
//     vis[u] = true;
//     parent[u] = p;
//     for (auto v : g[u])
//     {
//         if (v == p)
//             continue;
//         if (vis[v])
//         {
//             sv = v;
//             ev = u;
//             return true;
//         }
//         if (!vis[v])
//             if (dfs(v, u))
//                 return true;
//     }
//     return false;
// }

// bool visit_all()
// {
//     for (int i = 1; i <= n; ++i)
//     {
//         if (!vis[i])
//             if (dfs(i, -1))
//                 return true;
//     }
//     return false;
// }

// int main()
// {
   
//     cin >> n >> m;
//     g.resize(n + 1);
//     vis.resize(n + 1);
//     parent.resize(n + 1);
//     for (int i = 0; i < m; ++i)
//     {
//         int u, v;
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     if (!visit_all())
//     {
//         cout << "IMPOSSIBLE" << endl;
//         return 0;
//     }

//     int tv = ev;
//     vector<int> ans;
//     ans.push_back(ev);
//     while (tv != sv)
//     {
//         ans.push_back(parent[tv]);
//         tv = parent[tv];
//     }
//     ans.push_back(ev);
//     cout << ans.size() << endl;
//     for (auto c : ans)
//     {
//         cout << c << " ";
//     }
// }