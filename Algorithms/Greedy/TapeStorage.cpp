#include<bits/stdc++.h>
using namespace std;

int singleTapeRetrievalTime(vector<int> &lengths) {
    sort(lengths.begin(), lengths.end()); 
    int totalTime = 0, cumulative = 0;

    for (int len : lengths) {
        cumulative += len;
        totalTime += cumulative;
    }

    return totalTime;
}

int mutlipletaperetrievla(vector<int>lengths, int tapecount){
    sort(lengths.begin(), lengths.end());
    int j=0;
    int totalretrivaltime=0;

    vector<vector<int>>tape(tapecount);
    for(int i=0;i<lengths.size();i++){
        tape[j].push_back(lengths[i]);
        j= (j+1)%tapecount;
    }

    for(int i=0;i<tapecount;i++){
        int totalTime = 0, cumulative = 0;
        for (int len : tape[i]) {
            cumulative += len;
            totalTime += cumulative;
        }
        totalretrivaltime+=totalTime;
    }
    return totalretrivaltime;
}
int main(){

}
