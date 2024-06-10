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

vvi adj;
vi vis,color;


bool dfs(int u,int c,int par){
    vis[u]=1;
    color[u]=c;
    
    for(auto v:adj[u]){
        if(v==par)continue;
        if(color[v]==-1){
            if(!dfs(v,!c,u))return false;
        }
        if(color[u]==color[v])return false;
    }
    return true;
    }
int main()
{
    int n,m;
    in>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1,0);
    color.resize(n+1,-1);
    for(int i=0;i<m;i++){
        int u,v;
        in>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool f=true;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(!dfs(i,1,-1)){f=false;
            break;}
        }
    }
    if(!f){
        out<<"IMPOSSIBLE"<<el;
        rn;
    }
    for(int i=1;i<=n;i++){
        out<<color[i]+1<<" ";
    }


    return 0;
}