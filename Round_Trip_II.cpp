#include<iostream>
#include<bits/stdc++.h>
#include<stack> 
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
stack<int>recursionStack;
vi vis;
vector<bool>flag;

bool dfs(int u){
    vis[u]=1;
    recursionStack.push(u);
    flag[u]=true;
    
    for(auto v:adj[u]){
        
        if(!vis[v]){
            if(dfs(v))return true;
        }
        if(flag[v]){
            recursionStack.push(v);
            return true;
        }
    }
    recursionStack.pop();
    flag[u]=0;
    return false;


}
int main()
{
ios_base::sync_with_stdio(false); cin.tie(NULL);

in>>n>>m;
adj.resize(n+1);
vis.resize(n+1,0);
flag.resize(n+1,false);

for(int i=0; i<m;i++){
    int u,v;
    in>>u>>v;
    adj[u].push_back(v);
}
int f=0;
for(int i=1; i<=n;i++){
    if(!vis[i]){
        if(dfs(i)){
            f=1;
            break;
        }
    }
}
if(f){
vector<int>res;
int temp=recursionStack.top();
while(!recursionStack.empty()){
    res.push_back(recursionStack.top());
    recursionStack.pop();
    if(res.back()==temp && res.size()!=1){
        break;
    }
}
reverse(res.begin(),res.end());
out<<res.size()<<el;
for(int i=0; i<res.size();i++){
    out<<res[i]<<" ";
}
}
else out<<"IMPOSSIBLE"<<el;

    return 0;
}