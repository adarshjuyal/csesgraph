//Modified Dijsktra 
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

int n, m, k;
vector<vector<pair<ll, ll>>> adj;
vector<vector<ll>> dist;
const ll INF = 9e15;

void dij() {
    // Min-heap priority queue to select the node with the smallest distance
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push(make_pair(0, 1)); // Start with node 1 and distance 0

    while (!pq.empty()) {
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (dist[u][k-1] < d) continue;

        for (auto it : adj[u]) {
            ll v = it.first;
            ll c = it.second;

            if (dist[v][k-1] > d + c) {
                dist[v][k-1] = d + c;
                pq.push(make_pair(d + c, v));
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> n >> m >> k;
    adj.resize(n + 1);
    dist.resize(n + 1, vector<ll>(k, INF));

    dist[1][0] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        ll x;
        cin >> u >> v >> x;
        adj[u].push_back(make_pair(v, x));
    }

    dij();

    for (int i = 0; i < k; i++) {
        if (dist[n][i] == INF) {
            cout << -1 << " ";
        } else {
            cout << dist[n][i] << " ";
        }
    }
    cout << endl;

    return 0;
}