// 2025/04/04
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
    public:
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            return dfsTree(root).first;
        }
    
        pair<TreeNode*, int> dfsTree(TreeNode* nowNode){
            if(nowNode == nullptr) return {nullptr, 0};
    
            auto [leftNode, leftdepth] = dfsTree(nowNode->left);
            auto [rightNode, rightdepth] = dfsTree(nowNode->right);
    
            if(leftdepth > rightdepth) return {leftNode, leftdepth + 1};
            else if(rightdepth > leftdepth) return {rightNode, rightdepth + 1};
            else return {nowNode, leftdepth + 1}; // 因為此時 leftdepth == rightdepth，這裡取 leftdepth + 1
        }
    };