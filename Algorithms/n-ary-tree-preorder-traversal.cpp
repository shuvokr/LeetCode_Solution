// Link: https://leetcode.com/problems/n-ary-tree-preorder-traversal
// Tag : Simple recursion

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> result;
    vector<int> preorder(Node* root) {
        if(root == NULL) return result;
        solve(root);
        return result;
    }
    void solve(Node* root) {
        if(root == NULL) return;
        result.push_back(root->val);
        for(auto child: root->children) solve(child);
    }
};
