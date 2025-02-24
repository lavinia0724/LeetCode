// 2025/02/24
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
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            vector<int> indexInPostorder(preorder.size()+1);   
            for(int i = 0; i < preorder.size(); ++i){
                indexInPostorder[postorder[i]] = i;
            }
            return constructTree(0, preorder.size()-1, 0, preorder, indexInPostorder);
        }
    
        TreeNode* constructTree(int preStart, int preEnd, int postStart, vector<int>& preorder, vector<int>& indexInPostorder){
            if(preStart > preEnd) return NULL;
    
            if(preStart == preEnd) return new TreeNode(preorder[preStart]);
    
            int leftRoot = preorder[preStart + 1];
            int numOfNodeInLeft = indexInPostorder[leftRoot] - postStart + 1; // the number of nodes in the left subtree
    
            TreeNode* root = new TreeNode(preorder[preStart]);
            root->left = constructTree(preStart + 1, preStart + numOfNodeInLeft, postStart, preorder, indexInPostorder);
            root->right = constructTree(preStart + numOfNodeInLeft + 1, preEnd, postStart + numOfNodeInLeft, preorder, indexInPostorder);    
    
            return root;
        }
    };
    
    /*
    preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
    indexInPostorder = [0,6,2,5,0,1,3,4]
    
    constructTree(0, 6, 0, preorder, indexInPostorder)
    leftRoot = preorder[0+1] = 2
    numOfNodeInLeft = indexInPostorder[2] - 0 + 1 = 2 - 0 + 1 = 3 // 左子樹有三個點
    root = preorder[0] = 1
    root->left = constructTree(1, 3, 0, preorder, indexInPostorder)
    root->right = constructTree(4, 6, 3, preorder, indexInPostorder)
    
    
    root->left:
    constructTree(1, 3, 0, preorder, indexInPostorder)
    leftRoot = preorder[1+1] = 4
    numOfNodeInLeft = indexInPostorder[4] - 0 + 1 = 0 - 0 + 1 = 1
    root = preorder[1] = 2
    root->left = constructTree(2, 2, 0, preorder, indexInPostorder)
    root->right = constructTree(3, 6, 1, preorder, indexInPostorder)
    
    root->left:
    constructTree(2, 2, 0, preorder, indexInPostorder)
    preStart == preEnd return 找到葉子了
    
    ...
    最後會獲得一顆完整的樹
    */