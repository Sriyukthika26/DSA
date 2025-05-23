#include <iostream>
#include <vector>

using namespace std;

int boosterCount = 0;

void dfs(int node, int parent, int accumulatedLoss, vector<vector<pair<int,int>>>&tree, int losslimit) {
    if (accumulatedLoss > losslimit) {
        // Place booster here
        boosterCount++;
        accumulatedLoss = 0; // Reset loss after booster
    }

    for (auto edge : tree[node]) {
        if (edge.first != parent) {
            dfs(edge.first, node, accumulatedLoss + edge.second, tree, losslimit);
        }
    }
}

int main() {
    int n, L;
    cout << "Enter number of nodes and loss tolerance level: ";
    cin >> n >> L;

    vector<vector<pair<int,int>>> tree(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v, loss;
        cin >> u >> v >> loss;
        tree[u].push_back({v, loss});
        tree[v].push_back({u, loss});
    }

    // Start DFS from root node 0
    dfs(0, -1, 0, tree,L);

    cout << "Minimum boosters needed: " << boosterCount << endl;
    return 0;
}