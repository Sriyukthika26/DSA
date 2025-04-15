#include<bits/stdc++.h>
using namespace std;
//unstable sort
//used when memory is concerned, as it doesnot use extra space , inplace sorting
// in built sort function is based on quick sort
//random access is req , hence can't be used for linkedlist.

int partition(vector<int>&a, int l , int r){
    int pivot = a[r];
    int i = l-1;
    for(int j = l; j<r;j++){
        if(a[j]<pivot) swap(a[++i], a[j]);
    }
    swap(a[++i], a[r]);   //indexes

    return i;
}

void Quicksort(vector<int>&a, int l, int r){
    if(l>=r) return;
    int piidx = partition(a, l,r);
    Quicksort(a, l,piidx-1);
    Quicksort(a, piidx+1, r);
}

int main(){
    vector<int>arr ={1,3,5,2,10,9,8};
    Quicksort(arr,0,6);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
}