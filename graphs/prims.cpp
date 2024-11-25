// program for Prim's Minimum Spanning Tree (MST) algorithm.
// This is for adjacency matrix representation of the graph


#include<bits/stdc++.h>
using namespace std;

#define v 9

// function to find the node with minimum weight from the set of nodes not yet included in MST
int minkey(int key[], bool mst[]){
    int min = INT_MAX, minidx= -1;
    for(int i=0;i<v;i++){
        if(key[i]< min && mst[i]==false){
            min = key[i], minidx = i;
        }
    }
    return minidx;
}

// constructed MST stored in parent[]
void printmst(int parent[], int key[]){
    cout<<"EDGE \tPARENT \tWeight\n";
	
	for(int i=0; i<v; i++)
	{
		cout<<i<<"\t"<<parent[i]<< "\t" << key[i]<<endl;
	}
}

void MST(int* graph){
    int parent[v]; // to store constructed MST
    int key[v];
    bool mst[v]; // check whether node is included in MST

    for(int i=0;i<v;i++){
        key[i] = INT_MAX;
        mst[i] = false;
    } 
    key[0] = 0;
    parent[0] = -1;
    
    for(int i=0 ; i<v;i++){
        int u = minkey(key, mst);  // pick the minmum weight node from set of nodes not yet included in mst
        mst[u] = true;  //add this to mst
        for(int j=0;j<v;j++){
            int k = *((graph+u*v)+j);
            if(k< key[j] && k!=0){
                key[j] = k;
                parent[j] = u;
            }
        } 
    }

    printmst(parent, key);
}

int main(){
	int grap[v][v] = {{0,4,0,0,0,0,0,8,0}, 
					{4,0,8,0,0,0,0,11,0},
					{0,8,0,7,0,4,0,0,7}, 
					{0,0,7,0,9,14,0,0,0}, 
					{0,0,0,9,0,10,0,0,0},
                    {0,0,4,14,10,0,2,0,0},
                    {0,0,0,0,0,2,0,1,6},
                    {8,11,0,0,0,0,1,0,7},
                    {0,0,7,0,0,0,6,7,0}};
	MST((int*)grap);
}