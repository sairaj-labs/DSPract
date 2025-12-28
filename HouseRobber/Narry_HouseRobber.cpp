#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    vector<Node*> children;

    Node(int x) {
        this->val = x;
    }
};

pair<int,int> solve(Node* root) {
    if (!root) return {0, 0};

    int take = root->val;
    int skip = 0;

    for (Node* child : root->children) {
        auto p = solve(child);
        int childTake = p.first;
        int childSkip = p.second;

        take += childSkip;
        skip += max(childTake, childSkip);
    }

    return {take, skip};
}

int robNaryTree(Node* root) {
    auto p = solve(root);
    return max(p.first, p.second);
}

int main() {
    /*
            10
          /  |  \
         2   3   5
        / \      \
       7   1      4
    */

    Node* root = new Node(10);

    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    Node* child3 = new Node(5);

    root->children.push_back(child1);
    root->children.push_back(child2);
    root->children.push_back(child3);

    child1->children.push_back(new Node(7));
    child1->children.push_back(new Node(1));

    child3->children.push_back(new Node(4));

    cout << "Maximum money the robber can get: "
         << robNaryTree(root) << endl;

    return 0;
}
