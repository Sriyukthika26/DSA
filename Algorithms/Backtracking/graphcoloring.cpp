#include <bits/stdc++.h>
using namespace std;

bool color(int n, vector <vector<int>> &adj, int ind, int m, vector<int> &col){
    if(ind==n) return true;
    for(int i=0; i<m; i++){
        bool found=0;
        for(int v:adj[ind]){
            if(col[v]==i){
                found=1;
                break;
            }
        }
        if(!found){
            col[ind]=i;
            if(color(n,adj,ind+1,m,col)) return true;
            col[ind]=-1;
        }
    }
    return false;
}

//o(m^n) time complexity and o(n) space complexity

int main() {
    int n;
    int m;
    cin>>n>>m;
    vector <vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int m;
    cin>>m;
    vector<int> col(n,-1);
    bool poss= color(n,adj,0,m,col);
    if(poss){
        for(int i=0; i<n; i++) cout<<col[i]<<" ";
        cout<<"\n";
    }
    else cout<<"Not Possible!\n";
    return 0;
}