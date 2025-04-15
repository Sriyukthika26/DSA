#include<bits/stdc++.h>
using namespace std;

void sumofsubsets(int ind, vector<int>&num, int m, int sum, vector<int>&ds, vector<vector<int>>&ans){
    if(sum==m){
        for(auto it: ds){
            cout<<it<<" ";
        }
        cout<<"\n";
        ans.push_back(ds);
        return;
    }
    if(ind == num.size()){
        return;
    }
    ds.push_back(num[ind]);
    sumofsubsets(ind+1, num, m, sum+num[ind], ds, ans);
    ds.pop_back();
    sumofsubsets(ind+1, num, m, sum, ds, ans);
}

//o(2^n) time complexity and o(n) space complexity


int main(){
    vector<int> num =  {11, 13, 24, 7};
    vector<int>ds; vector<vector<int>>ans;
    sumofsubsets(0, num, 31, 0, ds, ans);
}