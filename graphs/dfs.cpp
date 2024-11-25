#include<bits/stdc++.h>
using namespace std;
void dfsrec(vector<vector<int>>&adj, vector<bool>&visited, int s){
    visited[s] = true;
    cout<<s<<" ";
     for(int i: adj[s]){
        if(visited[i]==0){
            dfsrec(adj, visited, i);
        }
    }
}

void dfs(vector<vector<int>>&adj , int s){
    vector<bool>visited(adj.size(), false);
    dfsrec(adj,visited,s);                                          
}