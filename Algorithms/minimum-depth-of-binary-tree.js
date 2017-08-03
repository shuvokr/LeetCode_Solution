//https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
var minDepth = function(root) {
    if(root === null) return 0;
    if(root.left === null) return 1 + minDepth(root.right);
    if(root.right === null) return 1 + minDepth(root.left);
    return Math.min(1 + minDepth(root.left), 1 + minDepth(root.right));
};
