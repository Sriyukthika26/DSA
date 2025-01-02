#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ppb pop_back()



void printseq(int l, vector<int>a, vector<int>&ds, int n){
    if(l==n){
        for(auto it: ds){
            cout<<it<<" ";
        }
        cout<<"\n";
        return;
    }

    ds.pb(a[l]);
    printseq(l+1,a,ds,n);
    ds.pop_back(); 
    printseq(l+1, a, ds,n);  
}
bool printsum(int l, vector<int>&ds, vector<int>a, int sum, int k){
    if(l==a.size()){
        if(sum==k){
            for(auto it: ds){
                cout<<it<<" ";
            }
            return true;
        }
        return false;
    }
    ds.pb(a[l]);
    if(printsum(l+1, ds, a, sum+a[l], k)){
        return true;
    }
    ds.pop_back();
    if(printsum(l+1, ds, a, sum, k)) return true;

    return false;
}

void printsumuni(int l, vector<int>&ds, vector<int>a, int sum, int k){
    if(l==a.size()){
        if(sum==k){
            for(auto it: ds){
                cout<<it<<" ";
            }
            cout<<"\n";    
        }
        return;
    }
    ds.pb(a[l]);
    printsumuni(l+1, ds, a, sum+a[l],k);
    ds.pop_back();
    printsumuni(l+1, ds, a, sum, k);
}

int printseqsum(int l,vector<int>c, int sum, int n){
    if(l==c.size()){
        if(sum==n){
            return 1;
        }
        return 0;
    }
    int cnt1 = printseqsum(l+1,c,sum+c[l],n);
    int cnt2 = printseqsum(l+1,c,sum,n);

    return cnt1+cnt2;
}

void combinationsum(int l, vector<int>&ds, vector<int>a, int target){
    if(l==a.size()){
        if(target==0){
            for(auto it: ds){
                cout<<it<<" ";
            }
            cout<<"\n";
        }
        return;
    }
    ds.pb(a[l]);
    if(a[l]<=target){
        combinationsum(l+1, ds,a,target-a[l]);
    }
    ds.ppb;
    combinationsum(l+1,ds,a,target);
}

void combination2(int l, vector<int>&ds, vector<vector<int>>&ans,vector<int>a, int target){
        if(target==0){
            ans.pb(ds);
            return;
        }
        for(int j=l;j<a.size();j++){
            if(j>l && a[j]==a[j-1]) continue;
            if(a[j]>target) break;
            ds.pb(a[j]);
            combination2(j+1, ds, ans,a, target-a[j]);
            ds.ppb;
        }   
}
void subsetsum1(int l, vector<int>a, vector<int>&ds, int sum){
    if(l==a.size()){
        ds.pb(sum);
        return;
    }
    subsetsum1(l+1, a, ds,sum+a[l]);
    subsetsum1(l+1, a, ds, sum);
}

void subsetsum2(int l, vector<int>&ds, vector<int>a, vector<vector<int>>&ans){
    ans.pb(ds);
    for(int i= l;i<a.size();i++){
        if(i>l && a[i]==a[i-1]) continue;
        ds.pb(a[i]);
        subsetsum2(i+1, ds,a,ans);
        ds.ppb;
    }
}

void printpermu(vector<int>freq, vector<int>&ds, vector<int>a, vector<vector<int>>&ans){
    if(ds.size()==a.size()){
        ans.pb(ds);
        return;
    }
    for(int i=0;i< a.size();i++){
        if(!freq[i]){
            freq[i] = 1;
            ds.pb(a[i]);
            printpermu(freq,ds,a,ans);
            freq[i]=0;
            ds.ppb;
        }
    }
}

void printpermu2(int l, vector<int>&a, vector<vector<int>>&ans){
    
    if(l==a.size()){
        ans.pb(a);
        return;
    }
    for(int i=l;i<a.size();i++){
        swap(a[l],a[i]);
        printpermu2(l+1, a, ans);
        swap(a[l],a[i]);
    }
}
int32_t main(){
    vector<int>a = {1,2,3};
    vector<int>ds; vector<vector<int>>ans;
    sort(a.begin(),a.end());
    // cout<<printseqsum(0,a,0,3);
    // combinationsum(0,ds,a,5);
    // printsumuni(0, ds, a, 0, 5);
    // combination2(0,ds,ans,a,5);
    // for(int  i=0;i<ans.size();i++){
    //     for(auto it: ans[i]){
    //         cout<<it<<" ";
    //     }
    //     cout<<"\n";
    // }
    // vector<int>b = {3,1,4};
    // subsetsum1(0,b,ds,0);
    // sort(ds.begin(), ds.end());
    // for(auto it: ds){
    //     cout<<it<<" ";
    // }
    // subsetsum2(0,ds,a,ans);
    // for(int  i=0;i<ans.size();i++){
    //     for(auto it: ans[i]){
    //         cout<<it<<" ";
    //     }
    //     cout<<"\n";
    // }
    printpermu2(0,a,ans);
    for(int i=0;i<ans.size();i++){
        for(auto it: ans[i]){
            cout<<it<<" ";
        }
        cout<<"\n";
    }




}