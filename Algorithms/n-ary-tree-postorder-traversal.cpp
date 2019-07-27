// Link : https://leetcode.com/problems/n-ary-tree-postorder-traversal/
// Tag : Recursion

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
    vector<int> postorder(Node* root) {
        if(root == NULL) return result;
        solve(root);
        return result;
    }
    void solve(Node* root) {
        if(root == NULL) return;
        for(auto child: root->children) solve(child);
        result.push_back(root->val);
    }
};
