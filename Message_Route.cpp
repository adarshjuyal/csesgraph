//bfs
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define forn(i, s, n) for (int i = s; i < int(n); i++)
#define in cin
#define out cout
#define el endl
#define rn return 0

typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
    int n, m;
    in >> n >> m;

    
    vvi adj(n + 1);
    vi vis(n + 1, 0);
    vi path(n + 1, 0);

    
    for (int i = 0; i < m; i++)
    {
        int u, v;
        in >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

   
    queue<int> q;
    vis[1] = 1;
    q.push(1);
    bool f = false;

 
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (node == n)
        {
            f = true;
            break;
        }
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
                path[it] = node;
            }
        }
    }


    if (f)
    {
        vi ans;
        for (int at = n; at != 0; at = path[at])
        {
            ans.push_back(at);
        }
        reverse(ans.begin(), ans.end());
        out << ans.size() << el;
        for (auto x : ans)
        {
            out << x << " ";
        }
        out << el;
    }
    else
    {
        out << "IMPOSSIBLE" << el;
    }

    return 0;
}
