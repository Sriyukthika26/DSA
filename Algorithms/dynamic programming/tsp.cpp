#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <climits>

using namespace std;

const int N = 4;
int cost[N][N] = {
    {0, 10, 15, 20},
    {5, 0, 9, 10},
    {6, 13, 0, 12},
    {8, 8, 9, 0}
};

// Key for memoization: pair of (currentNode, remainingNodesSet)
map<pair<int, set<int>>, int> dp;
map<pair<int, set<int>>, int> parent;

// Recursive function g(i, S)
int tsp(int i, set<int> S) {
    if (S.empty())
        return cost[i][0]; // Return to start node

    pair<int, set<int>> key = {i, S};
    if (dp.count(key))
        return dp[key];

    int minCost = INT_MAX;
    int nextNode = -1;

    for (int j : S) {
        set<int> S2 = S;
        S2.erase(j);
        int temp = cost[i][j] + tsp(j, S2);
        if (temp < minCost) {
            minCost = temp;
            nextNode = j;
        }
    }

    parent[key] = nextNode;
    return dp[key] = minCost;
}

// Function to reconstruct path
void printPath(int start, set<int> S) {
    cout << start + 1 << " ";
    while (!S.empty()) {
        int next = parent[{start, S}];
        S.erase(next);
        start = next;
        cout << start + 1 << " ";
    }
    cout << "1" << endl;
}

int main() {
    set<int> nodes = {1, 2, 3}; // Nodes except starting node 0
    int result = tsp(0, nodes);
    cout << "Minimum tour cost: " << result << endl;
    cout << "Optimal tour: ";
    printPath(0, nodes);
    return 0;
}