#include<bits/stdc++.h>
using namespace std;
//run time o(|V| + |E|)

void bfs(vector<vector<int>>&adj, int s){
    queue<int>q;
    vector<bool>visited(adj.size(), false);
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<" ";

        for(int i: adj[x]){
            if(visited[i]==false){
                visited[i]=true;
                q.push(i);
            }
        }
    }
}

