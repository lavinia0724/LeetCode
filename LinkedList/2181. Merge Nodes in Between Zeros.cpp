/** 2024/07/04
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
    ListNode* mergeNodes(ListNode* head) {  
        ListNode* prev = head;
        ListNode* now = head;
        while(true){
            int sum = 0;
            while(now->next->val != 0){
                sum += now->next->val;
                now = now->next;
            }
            prev->val = sum;
            now = now->next;
            if(now->next == nullptr){
                prev->next = nullptr;
                break;
            }
            prev->next = now;
            prev = prev->next;
        }
        return head;
    }
};