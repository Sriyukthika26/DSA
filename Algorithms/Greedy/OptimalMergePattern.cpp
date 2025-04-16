#include <bits/stdc++.h>
using namespace std;

int optimalMerge(vector<int>& files) {
    priority_queue<int, vector<int>, greater<int>> pq(files.begin(), files.end());
    int totalCost = 0;

    while (pq.size() > 1) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();

        int merged = first + second;
        totalCost += merged;

        pq.push(merged);
    }

    return totalCost;
}

int main() {
    int n;
    cin >> n;

    vector<int> files(n);
    cout << "Enter sizes of each file:\n";
    for (int i = 0; i < n; ++i) {
        cin >> files[i];
    }

    int result = optimalMerge(files);
    cout << "Minimum number of comparisons needed: " << result << endl;

    return 0;
}
