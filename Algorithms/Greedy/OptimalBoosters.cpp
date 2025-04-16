#include <iostream>
#include <vector>
using namespace std;

int boosterCount = 0;

int dfs(int node, int parent, vector<vector<pair<int,int>>>& tree, int L) {
    int maxLoss = 0;

    for (auto& edge : tree[node]) {
        if (edge.first != parent) {
            int childLoss = dfs(edge.first, node, tree, L) + edge.second;
            if (childLoss > L) {
                // Booster needed at child
                boosterCount++;
            } else {
                maxLoss = max(maxLoss, childLoss);
            }
        }
    }

    return maxLoss;
}

int main() {
    int n, L;
    cout << "Enter number of nodes and loss threshold (L): ";
    cin >> n >> L;

    vector<vector<pair<int,int>>> tree(n);

    cout << "Enter edges (u v loss):" << endl;
    for (int i = 0; i < n - 1; i++) {
        int u, v, loss;
        cin >> u >> v >> loss;
        tree[u].push_back({v, loss});
        tree[v].push_back({u, loss});
    }

    dfs(0, -1, tree, L); // assuming 0 is root
    cout << "Minimum number of boosters required: " << boosterCount << endl;

    return 0;
}
