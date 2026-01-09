// 2026/01/09
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
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) return {0, nullptr}; // 如果此 node 是 null

        auto [leftdistance, leftnode] = dfs(root->left); // 左子樹最深深度, 
        auto [rightdistance, rightnode] = dfs(root->right);

        // 當前的 node 他的左右子樹若 dist 相同，代表此 node 即是這題要的 LCA
        if (leftdistance == rightdistance) return {leftdistance + 1, root}; 

        // 如果左或右子樹 dist 不相同，代表他之下還有人可以成為 smallest subtree 的 LCA
        if (leftdistance > rightdistance) return {leftdistance + 1, leftnode};
        else return {rightdistance + 1, rightnode};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second; // 回傳 treenode
    }
};