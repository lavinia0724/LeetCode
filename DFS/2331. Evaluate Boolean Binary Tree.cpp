/** 2024/05/16
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
    bool dfs(TreeNode* now){
        if(now->val == 0){
            return false;
        }
        else if(now->val == 1){
            return true;
        }
        else if(now->val == 2){
            return dfs(now->left) | dfs(now->right);
        }
        else{
            return dfs(now->left) & dfs(now->right);
        }
    }

    bool evaluateTree(TreeNode* root) {
        if(root->val == 0){
            return false;
        }
        else if(root->val == 1){
            return true;
        }
        else if(root->val == 2){
            return dfs(root->left) | dfs(root->right);
        }
        else{
            return dfs(root->left) & dfs(root->right);
        }
    }
};