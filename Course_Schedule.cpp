//topological sort
#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
#define ll long long
#define forn(i,s, n) for (int i = s; i < int(n); i++)
#define in cin
#define out cout
#define el endl
#define rn return 0 
typedef vector<int> vi; 
typedef vector<vi> vvi;

int n,m;
vvi adj;
vi inDegree;
vi res;

void topoSort(){
    queue<int>q;
    for(int i=1; i<=n;i++){
        if(inDegree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        res.push_back(u);
        for(auto v:adj[u]){
            inDegree[v]--;
            if(inDegree[v]==0)q.push(v);
        }
    }

}

int main()
{
ios_base::sync_with_stdio(false); cin.tie(NULL);
    in>>n>>m;
    adj.resize(n+1);
    inDegree.resize(n+1,0);
    

    for(int i=0; i<m;i++){
        int u,v;
        in>>u>>v;
        adj[u].push_back(v);
        inDegree[v]++;
    }
    topoSort();
    if(res.size()!=n){
        out<<"IMPOSSIBLE"<<el;
    }
    else {
        for(auto it:res){
            out<<it<<" ";
        }
    }
    out<<el;
    return 0;
}