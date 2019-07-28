// Link : https://leetcode.com/problems/n-ary-tree-level-order-traversal

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
    vector< vector<int> > ret;
    int depth = 0;
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return ret;
        ret.assign(1001, vector<int>());
        solve(root, 0);
        depth++;
        
        vector<vector<int>> result;
        result.assign(depth, vector<int>());
        for(int i = 0; i < depth; i++)
            result[i] = ret[i];
        return result;
    }
    void solve(Node* tree, int pos) {
        if(tree == NULL) return;
        depth = depth < pos ? pos : depth;
        ret[pos].push_back(tree->val);
        for(auto child: tree->children)
            solve(child, pos + 1);
    }
};
