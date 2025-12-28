/*
Perfect! The Maximum Weight Independent Set (MWIS) in Trees is essentially the same problem as House Robber III or Binary Tree Maximum Non-Adjacent Sum, just stated in graph-theory language.
Let me explain clearly.
🔹 Problem Statement (Simple English)
Given a tree where each node has a weight:
Pick a subset of nodes so that no two adjacent nodes (parent-child) are picked.
Maximize the sum of the selected nodes’ weights.
🔹 Observation
If you pick a node → cannot pick its children.
If you skip a node → children can be picked or skipped.

This is exactly the same logic as the previous tree robbery problems.
🔹 DP Idea (Tree DP)
For each node, compute two values:
take → max sum if we take this node
skip → max sum if we skip this node
Formulas
take = node.val + sum(skip(child) for all children)
skip = sum(max(take(child), skip(child)) for all children)
Return {take, skip} from each node.
At the root, the answer is max(take, skip).
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x) {
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Returns {take, skip}
pair<int,int> solve(TreeNode* root) {
    if (!root) return {0, 0};

    auto left = solve(root->left);
    auto right = solve(root->right);

    int take = root->val + left.second + right.second;
    int skip = max(left.first, left.second) + max(right.first, right.second);

    return {take, skip};
}

int maximumWeightIndependentSet(TreeNode* root) {
    auto p = solve(root);
    return max(p.first, p.second);
}
