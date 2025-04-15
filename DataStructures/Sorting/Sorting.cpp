#include<bits/stdc++.h>
using namespace std;

//max no. of swaps in worst case(descending order= n(n-1)/2), sc:o(1)
// therefore in worst case time complexity is o(N^2)
//Best case: o(N)
//stable sorting algo
void Bubblesort(vector<int>&a){
    int n = a.size();
    for(int j=0; j< n-1;j++){
        bool isswap = false;
        for(int i=0;i<n-j-1;i++){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                isswap = true;                
            } 
        }
        if(!isswap) break;
    }
}

//TC: N(N-1)/2 both worst & best case o(N^2), sc:o(1)
//Unstable sorting algo
// Max swaps = o(N)
//used when array has only few unsorted elements
void Selectionsort(vector<int>&a){
    int n = a.size();
    for(int i = 0; i<n-1;i++){
        int min_idx = i;
        for(int j=i+1;j<n ; j++){
            if(a[j]<a[min_idx]) min_idx = j;
        }
        swap(a[i],a[min_idx]);
    }
}

//worst case : descending order- n(n-1)/2 tc: o(n^2)
//best case:o(N)
//stable algo
void Insertionsort(vector<string>&a){
    int n =  a.size();
    for(int i = 1; i< n;i++){
        string curr = a[i];
        int j = i-1;
        while(j>=0 and a[j]>curr){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = curr;
    }
}

int main(){
    vector<string>a = {"papaya", "lime", "banana"}; //  20 60 50 40 10 
    Insertionsort(a);
    for (int i = 0; i < a.size(); i++) cout<<a[i]<<" ";
}