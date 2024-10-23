#include<bits/stdc++.h>
using namespace std;

void Countsort(vector<int>&a, int exp){
    int n = a.size();
    vector<int>cnt(10,0);
    vector<int>ans(n);

    for(int i=0;i<n;i++){
        cnt[(a[i]/exp)%10]++;
    }                                                   //int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    for(int i=1;i<10;i++){               //2 2 4 4 5 7 8 8 8 8
        cnt[i]+= cnt[i-1];               //0 1 2 3 4 5 6 7 8 9
    }

    for(int i=n-1;i>=0;i--){
        ans[--cnt[(a[i]/exp)%10]] = a[i];      // 0  1  2  3  4  5  6  7  8  9
    }
    a = ans;                                          // 170 90 802 2 24 45 75 66
}

void Radixsort(vector<int>&a){
    int m = *max_element(a.begin(), a.end());

    for(int i=1; m/i>0; i=i*10){
        Countsort(a, i);
    }
}

int main(){
    vector<int>a = { 170, 45, 75, 90, 802, 24, 2, 66 };
    Radixsort(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    
}