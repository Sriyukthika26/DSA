#include<bits/stdc++.h>
using namespace std;

#define v 9

int minkey(int key[], bool mst[]){
    int mini = INT_MAX; int minidx = -1;
    for(int i=0;i<v;i++){
        if(key[i]<mini &&mst[i]==false){
            mini = key[i]; minidx = i;
        }
    }
    return minidx;
}

void printmst(int parent[], int key[]){
    cout<<"EDGE \tParent \tweight"<<"\n";
    for(int i=0;i<v;i++){
        cout<<i<<"\t"<<parent[i]<<"\t"<<key[i]<<"\n";
    }
}

void MST(int* graph){
    int parent[v];
    int key[v];
    bool mst[v];
    
    for(int i=0;i<v;i++){
        key[i] = INT_MAX;
        mst[i]=false;
    }
    key[0]=0;
    parent[0] = -1;
    for(int i=0;i<v;i++){
        int u =minkey(key,mst);
        mst[u]=true;
        for(int j=0;j<v;j++){
            int k  = *((graph+u*v)+j);
            if(k && k< key[j]){
                key[j]=k;
                parent[j]=u;
            }
        }
        printmst(parent,key);
    }
    
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