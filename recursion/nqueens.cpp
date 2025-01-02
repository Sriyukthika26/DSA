#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ppb pop_back()
//brute
bool fill(int i, int n,int col, vector<string>d){
    int row = i; int colu = col;
    while(row>=0 && colu>=0){
        if(d[row][colu]=='q') return false;
        row--;
        colu--;
    }
    colu = col;
    while(colu>=0){
        if(d[i][colu]=='q') return false;
        colu--;
    }
    row= i, colu=col;
    while(row<n && colu>=0){
        if(d[row][colu]=='q') return false;
        row++; colu--;
    }
    return true;
}

void nqueens(int col, int n, vector<vector<string>>&ans, vector<string>&d){
    if(col==n){
        ans.pb(d);
        return;
    }
    for(int i=0;i<n;i++){
        if(fill(i,n,col,d)){
            d[i][col] = 'q';
            nqueens(col+1,n,ans,d);
            d[i][col]='.';
        }
    }
}
//optimal

void nqueens2(int col,int n, vector<vector<string>>&ans, vector<string>&d, vector<int>&leftrow, vector<int>&upperdia, vector<int>&lowerdia){
    if(col==n){
        ans.pb(d);
        return;
    }
    for(int i=0;i<n;i++){
        if(leftrow[i]==0&& lowerdia[i+col]==0 && upperdia[n-1+col-i]==0){
            leftrow[i]= 1;
            lowerdia[i+col]=1;
            upperdia[n-1+col-i]=1;
            d[i][col]='q';
            nqueens2(col+1, n, ans,d,leftrow, upperdia, lowerdia);
            leftrow[i]= 0;
            lowerdia[i+col]=0;
            upperdia[n-1+col-i]=0;
            d[i][col]='.';
        }
    }

}

int32_t main(){
    int n;
    cin>>n;
    vector<string>d(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        d[i] = s;
    }
    vector<vector<string>>ans;
    // nqueens(0,n,ans,d);
    vector<int>leftrow(n,0); vector<int>upperdia(2*n-1, 0); vector<int>lowerdia(2*n-1, 0);
    nqueens2(0,n,ans,d,leftrow,upperdia,lowerdia);
    for(int i=0;i<ans.size();i++){
        for(auto it:  ans[i]){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
    
    
}