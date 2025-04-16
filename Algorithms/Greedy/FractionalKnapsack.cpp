#include <bits/stdc++.h>
using namespace std;

struct Item {
    int profit, weight;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;  // Sort in descending order of value/weight
}

double greedyKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);

    int n = items.size();
    vector<double> x(n, 0.0); // To store fraction of items taken
    int U = capacity;
    int i;

    for (i = 0; i < n; i++) {
        if (items[i].weight > U) break;
        x[i] = 1.0;
        U -= items[i].weight;
    }

    if (i < n) {
        x[i] = (double)U / items[i].weight;
    }

    double totalValue = 0.0;
    for (int j = 0; j < n; j++) {
        totalValue += x[j] * items[j].profit;
    }

    return totalValue;
}

int main() {
    int n, capacity;
    cin >> n;
    cin >> capacity;

    vector<Item> items;
    for (int i = 0; i < n; ++i) {
        int p, w;
        cin >> p >> w;
        items.push_back({p, w});
    }

    double maxProfit = greedyKnapsack(capacity, items);
    cout << "\nMaximum value in knapsack = " << maxProfit << endl;

    return 0;
}
