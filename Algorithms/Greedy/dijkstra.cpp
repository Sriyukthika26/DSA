#include<bits/stdc++.h>
using namespace std;

void dijkstra(int src, vector<vector<pair<int,int>>>adj, int V){
	vector<int>dist(V, 1e9);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

	dist[src]=0;
	pq.push({0,src});
	while(!pq.empty()){
		int dis = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		for(auto it: adj[node]){
			int w = it.first;
			int adjnode = it.second;
			if(dis+w< dist[adjnode]){
				dist[adjnode] = dis+w;
				pq.push({dist[adjnode], adjnode});
			}
		}
	}
	for(int i=0;i<V;i++){
		cout<<dist[i]<<" ";
	}
}

int main(){
	vector<vector<pair<int,int>>>adj = {{{2,1},{6,3}},
										{{2,0},{8,3},{5,4},{3,2}},
										{{3,1},{7,4}},
										{{6,0},{8,1},{9,4}},
										{{9,3},{5,1},{7,2}}};
										
	dijkstra(0,adj,5);
}
