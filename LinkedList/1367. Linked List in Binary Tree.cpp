// 2024/09/07
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfsTree(ListNode* head, TreeNode* root){
        if(root == NULL) return false; // 已經走完整棵樹，全都無法組成 LinkedList
        
        if(dfsLinkedList(head, root)) return true;
        else return dfsTree(head, root->left) || dfsTree(head, root->right); // if this root is is not in linkedlist, try its children
    }

    bool dfsLinkedList(ListNode* head, TreeNode* node){
        if(head == NULL) return true;  // 已經走完整個 LinkedList 且完全相符
        if(node == NULL) return false; // 已經走完整棵 Tree 但沒能組完整個 LinkedList

        if(head->val == node->val) return dfsLinkedList(head->next, node->left) || dfsLinkedList(head->next, node->right);
        else return false;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(dfsTree(head, root)) return true;
        else return false;
    }
};