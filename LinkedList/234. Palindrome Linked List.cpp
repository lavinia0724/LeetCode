/** 2024/03/21
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
    bool isPalindrome(ListNode* head) {
        int cnt = 0;
        ListNode* ptr = head;
        ListNode* RightPreves = NULL;
        while(ptr != NULL){
            ListNode* RightNode = new ListNode(ptr->val);   

            RightNode->next = RightPreves;
            RightPreves = RightNode;
            ptr = ptr->next;
            cnt++;
        }

        ListNode * RighHead = RightPreves;
        for(int i = 0; i < cnt/2; ++i){
            if(head->val != RighHead->val) return false;

            head = head->next;
            RighHead = RighHead->next;
        }
        return true;
    }
};