/** 2024/05/17 
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
    TreeNode* dfs(TreeNode* now, int target){
        if(now->left != NULL){
            now->left = dfs(now->left, target);
        }
        if(now->right != NULL){
            now->right = dfs(now->right, target);
        }

        if(now->val == target && now->left == NULL && now->right == NULL){
            return NULL;
        }
        else return now;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        root = dfs(root, target);
        return root;
    }
};