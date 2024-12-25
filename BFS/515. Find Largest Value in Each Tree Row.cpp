// 2024/12/25
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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};

        queue<pair<TreeNode*, int>> q;
        vector<int> ans;
        int maxi = INT_MIN, treeRow = 0;
        q.push({root, treeRow});

        while(!q.empty()){
            auto now = q.front();
            q.pop();
            if(now.second != treeRow){
                ans.push_back(maxi);
                maxi = INT_MIN;
                treeRow = now.second;
            }
            maxi = max(maxi, now.first->val);

            if(now.first->left != NULL) q.push({now.first->left, treeRow + 1});
            if(now.first->right != NULL) q.push({now.first->right, treeRow + 1});
        }
        ans.push_back(maxi);

        return ans;
    }
};