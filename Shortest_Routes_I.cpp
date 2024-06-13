#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define ll long long
#define forn(i, s, n) for (int i = s; i < int(n); i++)
#define in cin
#define out cout
#define el endl
#define rn return 0
typedef vector<int> vi;
typedef vector<vi> vvi;

vector<vector<pair<int, int> > > adj;
vector<ll> dist;
const ll MAXD = 1e17;
int n, m;

void dijkstra()
{
    for (int i = 0; i <= n; ++i)
    {
        dist[i] = MAXD;
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
    pq.push(make_pair(0, 1)); // (distance, node)
    dist[1] = 0;

    while (!pq.empty())
    {
        ll distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (distance > dist[node])
            continue;
        for (auto it : adj[node])
        {
            int next_node = it.first;
            ll edge_weight = it.second;
            if (distance + edge_weight < dist[next_node])
            {
                dist[next_node] = distance + edge_weight;
                pq.push(make_pair(dist[next_node], next_node));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    in >> n >> m;
    adj.resize(n + 1);
    dist.resize(n + 1, MAXD);

    for (int j = 0; j < m; j++)
    {
        int u, v, x;
        in >> u >> v >> x;
        adj[u].push_back(make_pair(v, x));
    }

    dijkstra();

    for (int i = 1; i <= n; i++)
    {
        out << dist[i] << " ";
    }
    out << el;

    return 0;
}

