/*
🔥 House Robber III — What Changes?
Now the houses are arranged as nodes of a binary tree, not a line or circle.
Rule:
If you rob a node, you cannot rob its children.
But you can rob its grandchildren.
So for every node you have two choices:

✔ Case 1 → Rob this node
Then you cannot rob its left or right child,
but you can rob the grandchildren.

✔ Case 2 → Do NOT rob this node
Then you are free to rob or not rob its children —
whichever gives more money.


✅ Recall what solve(node) returns
The function:
pair<int,int> solve(TreeNode* root)

returns:
{ rob, notRob }
Meaning:
first = rob → maximum money IF we rob this node
second = notRob → maximum money IF we do NOT rob this node
So:
left.first     → money if we rob the left child
left.second    → money if we do NOT rob the left child
And same for right.
🔥 Now your line:
int rob = root->val + left.second + right.second;
Meaning:
If we rob the current node,
then we cannot rob its children.
So:
we must take children’s notRob values
which are stored in left.second and right.second
👉 Because .second = “money if this child is NOT robbed”.
*/

// Watch Nikhil Lohia explanation for better clarity:
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    // Constructor using `this`
    TreeNode(int x) {
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Returns {rob, notRob}
pair<int,int> solve(TreeNode* root) {
    if (root == nullptr) return {0, 0};

    auto left  = solve(root->left);
    auto right = solve(root->right);

    // If we rob this node, we cannot rob children
    int rob = root->val + left.second + right.second;

    // If we don't rob this node, pick best for each child
    int notRob = max(left.first, left.second) 
               + max(right.first, right.second);

    return {rob, notRob};
}

int rob(TreeNode* root) {
    auto ans = solve(root);
    return max(ans.first, ans.second);
}
int main() {
    /*
            3
           / \
          2   3
           \    \
            3    1
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    cout << "Maximum money the robber can get: " << rob(root) << endl;

    return 0;
}
