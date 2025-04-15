#include<bits/stdc++.h>
using namespace std;

void addedge(vector<vector<int>>& mat, int i, int j){
    mat[i][j] = 1;
    mat[j][i] = 1;
}
//space = n^2
void displaymatrix(vector<vector<int>>mat){
    int v  = mat.size();
    for(int i = 0;i< v;i++){
        for(int j=0;j<v;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    
}