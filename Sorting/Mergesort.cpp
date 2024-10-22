#include<bits/stdc++.h>
using namespace std;
//used when large datasets
//stable sort
//linked list ->  merge sort

void Merge(vector<int>&a, int l , int mid, int r){
    int an = mid-l+1; int bn = r-mid;
    vector<int>a1(an), a2(bn);
    for(int i=0;i<an;i++) a1[i] = a[l+i];
    for(int i=0;i<bn; i++) a2[i] = a[mid+1+i];
    
    int i = 0, j=0, k=l;
    while( i < an && j< bn){
        if(a1[i]<=a2[j]){
            a[k++] = a1[i++];
        }
        else{
            a[k++] = a2[j++];
        }
    }
    while(i< an){
        a[k++]= a1[i++];
    }
    while(j< bn){ 
        a[k++] = a2[j++];
    }
}

void Mergesort(vector<int>&a, int l , int r){
    if(l>=r) return;                           
    int mid = (l+r)/2;
    Mergesort(a, l,mid);
    Mergesort(a, mid+1, r);
    Merge(a, l , mid, r); 
}

//drawbacks: slower for smaller tasks
// takes o(N) extra space
// goes through whole process even if array is sorted

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    Mergesort(a,0,n-1);
    for(int i=0; i<n;i++) cout<<a[i]<<" ";
    
}