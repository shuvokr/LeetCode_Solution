// Link: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// Tag : DFS

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
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        
        int value = 0;
        for(auto child: root->children)
            value = max(value, maxDepth(child));
        return value + 1;
    }
};
