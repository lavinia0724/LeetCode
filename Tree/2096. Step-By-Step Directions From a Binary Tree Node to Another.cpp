// 2024/07/24
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
    bool dfs(TreeNode* now, int target, string& Path){
        if(now->val == target) return true;

        string LeftPath, RightPath;

        Path += "L";
        if(now->left != nullptr && dfs(now->left, target, Path)) return true;
        Path.pop_back();

        Path += "R";
        if(now->right != nullptr && dfs(now->right, target, Path)) return true;
        Path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string StartPath = "", DestinationPath = "";
        dfs(root, startValue, StartPath); // from root to find startValue
        dfs(root, destValue, DestinationPath); // from root to find destValue

        int commonAncestor = 0;
        cout << StartPath << " " <<  DestinationPath << endl;
        while(StartPath[0] == DestinationPath[0]){
            StartPath.erase(0, 1);
            DestinationPath.erase(0, 1);
            commonAncestor;
        }

        string ans = "";
        for(int i = 0; i < StartPath.size() - commonAncestor; ++i) ans += "U";
        ans += DestinationPath;

        return ans;
    }
};