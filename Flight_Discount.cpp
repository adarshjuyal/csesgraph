#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define int  long long int
#define forn(i, s, n) for (int i = s; i < int(n); i++)
#define in cin
#define out cout
#define el endl
#define rn return 0
typedef vector<int> vi;
typedef vector<vi> vvi;

vector<vector<pair<int, int> > > adj;
vector<int > dist, disc;
int n, m;
const int MAXI = 9e17;

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = MAXI;
        disc[i] = MAXI;
    }
    dist[1]=0;
    disc[1]=0;
    
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
    pq.push(make_pair(0, make_pair(1, 0))); // Start with node 1, cost 0, and state 0 (not using discount)

    while (!pq.empty())
    {
        int u = pq.top().second.first;
        int d = pq.top().first;
        int f = pq.top().second.second;
        pq.pop();

        if (f == 1)
        {
            if (disc[u] < d)
                continue;
        }
        else
        {
            if (dist[u] < d)
                continue;
        }

        for (auto it : adj[u])
        {
            int v = it.first;
            int c = it.second;
            if (f == 0)
            {
                if (dist[v] > c + d)
                {
                    pq.push(make_pair(c + d, make_pair(v, 0)));
                    dist[v] = c + d;
                }
                if (disc[v] > d + c / 2)
                {
                    pq.push(make_pair(d + c / 2, make_pair(v, 1)));
                    disc[v] = d + c / 2;
                }
            }
            else
            {
                if (disc[v] > c + d)
                {
                    pq.push(make_pair(c + d, make_pair(v, 1)));
                    disc[v] = c + d;
                }
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    in >> n >> m;
    adj.resize(n + 1);
    dist.resize(n + 1);
    disc.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, x;
        in >> u >> v >> x;
        adj[u].push_back(make_pair(v, x));
    }

   

    solve();

    if (disc[n] == MAXI)
        out << -1 << el;
    else
        out << disc[n] << el;

    return 0;
}
