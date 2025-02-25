// 2025/02/25
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
 class FindElements {
    public:
        FindElements(TreeNode* root) {
            dfs(root, 0); // root 必為 0
        }
    
        void dfs(TreeNode* now, int succeedValue){
            elements[succeedValue]++;
            if(now->left != NULL) dfs(now->left, succeedValue * 2 + 1);
            if(now->right != NULL) dfs(now->right, succeedValue * 2 + 2);
        }
        
        bool find(int target) {
            if(elements.find(target) != elements.end()) return true;
            return false;
        }
    
    private:
        unordered_map<int, int> elements;
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */