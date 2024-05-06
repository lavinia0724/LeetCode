/** 2024/05/06
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(head == nullptr) return nullptr;

        // recursive 一路遞迴到最後一個 node
        // 最後一個點必留，所有其遞迴往回傳的上層(左邊)較小者的全不接到 head->next
        // 若有更大者，則留下最大者，head->next 為他
        head->next = removeNodes(head->next);

        if(head->next != NULL){
            if(head->val < head->next->val) return head->next;
            else return head;
        }
        else return head; // 最後一個節點直接迴傳
    }
};