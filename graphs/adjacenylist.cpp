#include<bits/stdc++.h>
using namespace std;

class adjnode{
public:
    int node;
    adjnode* next;

    adjnode(int dest){
        node = dest;
        next=NULL;
    }
};

class adjlist{
public:
    adjnode* head;
};

class graph{
public:
    int nodes;
    int edges;
    adjlist* arr;

    graph(int v, int e){
        nodes = v;
        edges = e;
        arr = new adjlist[v];
        for(int i=0;i<v;i++){
            arr[i].head = NULL;
        }
    }
};

void addgedge(graph* &g1, int src, int dest){
    adjnode* newnode = new adjnode(dest);
    if(g1->arr[src].head == NULL) g1->arr[src].head = newnode;
    else{
        adjnode* temp = g1->arr[src].head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next = newnode;
    }
}
