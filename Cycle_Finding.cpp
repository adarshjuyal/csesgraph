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

vector<pair<int,pair<int,ll> > >edges;
vector<ll>dist,relaxant;
int n, m;

void bellman_ford(){
    int x;
    for(int i=1;i<=n;i++){
        x=-1;
        for(auto e:edges){
            int u=e.first;
            int v=e.second.first;
            int d=e.second.second;
            if(dist[u]+d<dist[v]){
                dist[v]=dist[u]+d;
                relaxant[v]=u;
                x=v;
            }
        }
    }
    if(x==-1){
        out<<"NO"<<el;
    }
    else{

        for (int i = 1; i <= n; ++i)
        {
            x = relaxant[x];
        }

        vector<int> cycle;

        for (int v = x;; v = relaxant[v])
        {
            cycle.push_back(v);
            if (v == x and cycle.size() > 1)
                break;
        }

        reverse(cycle.begin(), cycle.end());

        cout << "YES" << endl;
        for (auto v : cycle)
        {
            cout << v << " ";
        }

        cout << endl;
    }
}

int main()
{
ios_base::sync_with_stdio(false); cin.tie(NULL);

in>>n>>m;
edges.resize(m);
dist.resize(n+1);
relaxant.resize(n+1);
for(int i=0; i<m;i++){
    int u,v;
    ll x;
    in>>u>>v>>x;
    edges.push_back(make_pair(u,make_pair(v,x)));
}
for (int i = 1; i <= n; ++i)
{
    relaxant[i] = -1;
}
bellman_ford();

    return 0;
}