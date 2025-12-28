/*
0: skip
├─ 1: skip
│   ├─ 2: skip
│   │   └─ 3: skip -> sum=0
│   │   └─ 3: take -> sum=4
│   └─ 2: take
│       └─ 3: skip -> sum=5
├─ 1: take
│   ├─ 2: skip
│   │   └─ 3: skip -> sum=2
│   └─ 2: take
│       └─ 3: skip -> sum=7
0: take
└─ 1: skip
    └─ 2: skip
        └─ 3: skip -> sum=3
        └─ 3: take -> sum=7

*/
#include <bits/stdc++.h>
using namespace std;

int solveMWIS(int node, vector<vector<int>>& G, vector<int>& weights, vector<bool>& taken) {
    int n = G.size();
    if (node == n) return 0;

    // Option 1: skip this node
    int ans = solveMWIS(node + 1, G, weights, taken);

    // Option 2: take this node if none of its neighbors are taken
    bool canTake = true;
    for (int neighbor : G[node]) {
        if (taken[neighbor]) {
            canTake = false;
            break;
        }
    }

    if (canTake) {
        taken[node] = true;
        ans = max(ans, weights[node] + solveMWIS(node + 1, G, weights, taken));
        taken[node] = false; // backtrack
    }

    return ans;
}

int main() {
    /*
        Example Graph:
        Node 0 (weight 3) - Node 1 (weight 2)
        Node 0 (weight 3) - Node 2 (weight 5)
        Node 1 (weight 2) - Node 3 (weight 4)
        Node 2 (weight 5) - Node 3 (weight 4)
    */

    int n = 4; // number of nodes
    vector<int> weights = {3, 2, 5, 4};

    // adjacency list
    vector<vector<int>> G(n);
    G[0].push_back(1); G[1].push_back(0);
    G[0].push_back(2); G[2].push_back(0);
    G[1].push_back(3); G[3].push_back(1);
    G[2].push_back(3); G[3].push_back(2);

    vector<bool> taken(n, false);

    int maxWeight = solveMWIS(0, G, weights, taken);
    cout << "Maximum Weight Independent Set: " << maxWeight << endl;

    return 0;
}
