//Cycle detection in undirected Graph
#include<bits/stdc++.h>
using namespace std;

bool CycleUtil(int v,vector<int> adj[],vector<bool>&visited,
vector<bool>&recstack){
    if(!visited[v]){
        visited[v] = true;
        recstack[v] = true;

        for(auto x : adj[v]){
            if(!visited[x] && CycleUtil(x,adj,visited,recstack)){
                return true;
            }
            else if(recstack[x]){
                return true;
            }
        }
    }
    recstack[v] = false;
    return false;
}

bool isCycle(int v,vector<int>adj[]){
    vector<bool>visited(v,0);
    vector<bool>recstack(v,0);

    for(int i=0; i<v; i++){
        if(CycleUtil(i,adj,visited,recstack)){
            return true;
        }
    }
    return false;
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<int> adj[n];
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
    }

    if(isCycle(n,adj)){
        cout<<"cycle is present";
    }
    else{
        cout<<"cycle is not present";
    }

    return 0;
}