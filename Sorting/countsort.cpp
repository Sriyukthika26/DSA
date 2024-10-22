#include<bits/stdc++.h>
using namespace std;
//stable sort
// should be used when max ~ o(N)

void Countsort(vector<int>&a){
    int n = a.size();
    int maxi = *max_element(a.begin(), a.end());
    vector<int>f(maxi+1,0);
    for(int i=0;i<n;i++){
        f[a[i]]++;
    }
    for(int i=1;i<=maxi;i++){
        f[i] += f[i-1];
    }
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        ans[--f[a[i]]] = a[i];
    }
    a = ans;
}


// sc: o(N+maxi), tc:o(N);
// not to be used for floating point no.s
//to use this for neg no.s we need to normalize the array, i.e subtract min element from all no.s
// not prefered if diparity btw no.s is high like {2, 465, 6789, 31}


int main(){
    vector<int>arr ={1,3,5,2,10,9,8};
    Countsort(arr);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
}