#include<bits/stdc++.h>
using namespace std;

int parent(int i){
    int p = (i-1)/2;
    return p;
}

void upheapify(vector<int>&a, int i){
    while(i!=0 && a[parent(i)]< a[i]){
        swap(a[parent(i)],a[i]);
        i = parent(i);
    }
}

void maxheapify(vector<int>&a, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;
    if(l<a.size() && a[l]>a[i]) largest=l;
    if(r<a.size() && a[r]>a[largest]) largest=r;
    if(largest!=i){
       swap(a[largest], a[i]);
       maxheapify(a,largest);
    } 
}

void insertheap(vector<int>&a, int key){
    a.push_back(key);
    int size = a.size();
    upheapify(a,size-1);
}

void buildheap(vector<int>&a){
    int length = a.size();
    int strt = length/2+1;
    for(int i = strt; i>=0;i--){
        maxheapify(a,i);
    }
}

int extractmax(vector<int>&a){
    int maxi = a[0];
    swap(a[0],a[a.size()-1]);
    a.pop_back();
    maxheapify(a,0);
    return maxi;
}

void maxheap_updatekey(vector<int>&a, int key, int i){
    if(a[i]>key){
        a[i]=key;
        maxheapify(a,i);
    }
    else{
        a[i]=key;
        upheapify(a,i);
    }
}

void buildheap1(vector<int>a){
    vector<int>b;
    for(int i=0;i<a.size();i++){
        insertheap(b,a[i]);
    }
}
//unstable sorting
void heapsort(vector<int>&a){
    buildheap(a);
    for(int i= a.size()-1; i>0;i--){
        swap(a[0], a[i]);
        maxheapify(a,0);
    }
}

int main(){
    
}