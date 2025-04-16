#include <bits/stdc++.h>
using namespace std;

void activitySelection(vector<pair<int, int>>& activities) {
    vector<int>ans;
    sort(activities.begin(), activities.end());

    int lastFinishTime = activities[0].first;
    ans.push_back(0);
    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].second >= lastFinishTime) {
            ans.push_back(i);
            lastFinishTime = activities[i].first;
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
//o(nlogn) time complexity and o(n) space complexity
//activity[i].first -> endtime,  activity[i].second -> starttime

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> activities(n);
    for (int i = 0; i < n; ++i) {
        cin >> activities[i].second >> activities[i].first;
    }
    activitySelection(activities);

    return 0;
}
