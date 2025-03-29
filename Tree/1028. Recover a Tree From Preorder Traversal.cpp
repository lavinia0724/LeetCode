// 2025/03/29
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
        TreeNode* recoverFromPreorder(string traversal) {
            stack<TreeNode*> stk;
            int depth = 0;
            for(int i = 0; i < traversal.size(); ){
                if(traversal[i] == '-'){
                    depth++;
                    i++;
                }
                else{  
                    int val = 0;
                    while(isdigit(traversal[i])){
                        val = val * 10 + (traversal[i] - '0'); // 可能會有多位數
                        i++;
                    }
    
                    TreeNode* nowNode = new TreeNode(val); // 建立現在這顆點，可以直接包 val 給他
                    
                    while(!stk.empty() && stk.size() > depth) stk.pop(); // 會 pop 直到剩下父親
                    
                    if(!stk.empty()){
                        if(stk.top()->left == NULL) stk.top()->left = nowNode;
                        else stk.top()->right = nowNode;
                    }
    
                    stk.push(nowNode);
                    depth = 0;
                }
            }
    
            while(stk.size() > 1) stk.pop();
            return stk.top(); // pop 直到最後剩下 root
        }
    };