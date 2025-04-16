#include<bits/stdc++.h>
using namespace std;

void multigraph(vector<vector<pair<int,int>>> adjlist){
    int n=adjlist.size();
    vector<int> cost(n,1e9);
    vector<int> next(n,-1);
    cost[n-1]=0;
    for(int i=n-2;i>=0;i--){
        int vertex=-1,minidis=1e9;
        for(auto it:adjlist[i]){
           int dis=it.second+cost[it.first];
           if(dis<minidis){
            minidis=dis;
            vertex=it.first;
           }
        }
        cost[i]=minidis;
        next[i]=vertex;
        cout<<i<<' '<<cost[i]<<' '<<next[i]<<endl;
    }
    cout<<cost[0]<<endl;
    cout<<0<<' ';
    int start=0;
    while(start!=(n-1)){
        start=next[start];
        cout<<start<<' ';
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<pair<int,int>>> adjlist(n);
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adjlist[u].push_back({v,wt});
    }
    multigraph(adjlist);
//o(n^2) time complexity and o(n) space complexity

}


