#include<bits/stdc++.h>
using namespace std;

void prims(int V, vector<vector<int>>&adjmat){
	priority_queue< pair<int,pair<int,int>>,
	 			    vector<pair<int,pair<int,int>>>, 
				    greater<pair<int,pair<int,int>>>>pq;
	
	vector<int>visited(V,0);
	vector<pair<int,int>>mst;
	int sum=0;
	pq.push({0,{0,-1}});
	
	while(!pq.empty()){
		int w = pq.top().first;
		int node = pq.top().second.first;
		int parent = pq.top().second.second;
		
		pq.pop();
		
		if(visited[node]==1) continue;
		visited[node] = 1;
		sum+= w;
		mst.push_back({parent, node});
		
		for(int j=0;j<V;j++){
			if(adjmat[node][j]!=0 && visited[j]==0){
				pq.push({adjmat[node][j],{ j, node}});
			}
		}
		
	}
	cout<<sum<<"\n";
	for(int i=1;i<mst.size();i++){
		cout<<mst[i].first<<" "<<mst[i].second<<"\n";
	}
	
		
}

int main(){
	vector<vector<int>>adjmat ={{0, 2,0,6,0},
								{2,0,3,8,5},{0,3,0,0,7},{6,8,0,0,9},{0,5,7,9,0}};
	prims(5, adjmat);
	
	
}
