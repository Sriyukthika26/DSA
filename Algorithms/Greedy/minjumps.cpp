#include<bits/stdc++.h>
using namespace std;

void minhops(vector<int>& arr) {
	int n = arr.size();
    vector<int>hops;
    int end = 0;
    int farthest = 0;
    int jumps=0;
	
    for (int i = 0; i < n - 1; i++) {
      farthest = max(farthest, i + arr[i]);
      if (farthest >= n - 1) {
        hops.push_back(i);
        jumps++;
        break;
      }
      if (i == end) {   
		hops.push_back(i);
		jumps++;           
        end = farthest;  
      }
    }
	
	hops.push_back(n-1);
	
	cout<<jumps<<"\n";
	
    for(int i=0;i<hops.size();i++){
		cout<<hops[i]<<" ";
	}
}

int main(){
	vector<int>arr = {1,3,5,9,3,2,6,7,6,8,9};
	//farthest=12   hops=2       end = 4 
	minhops(arr);             
	
}
//o(n) time complexity and o(1) space complexity