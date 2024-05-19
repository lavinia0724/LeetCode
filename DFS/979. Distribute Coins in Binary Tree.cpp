/** 2024/05/18
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
    /* 
    return 的值是我的左子樹或右子樹，目前還缺或多多少 coins
    但 ans 是計算步數，計算到當前這個節點，需要多少步才能給足夠多的 coins
    */
    int ans = 0;
    int dfs(TreeNode* now){
        if(now == NULL) return 0;
        int leftcoins = dfs(now->left);
        int rightcoins = dfs(now->right);
        ans += abs(leftcoins) + abs(rightcoins);
        return (now->val - 1) + leftcoins + rightcoins;
    }
    int distributeCoins(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};