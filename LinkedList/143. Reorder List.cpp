/** 2024/03/24
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
    void reorderList(ListNode* head) {
        ListNode* rightHead = head;
        ListNode* rightPreves = NULL;
        int cnt = 0;
        while(rightHead != NULL){
            ListNode* nowNode = new ListNode(rightHead->val);

            nowNode->next = rightPreves;
            rightPreves = nowNode;
            rightHead = rightHead->next;

            cnt++;
        }
        rightHead = rightPreves;

        ListNode* leftnxt = NULL;
        ListNode* rightnxt = NULL;
        for(int i = 0; i < cnt/2; ++i){
            leftnxt = head->next;
            rightnxt = rightHead->next;

            head->next = rightHead;
            if((i == (cnt/2)-1) && !(cnt & 1)){
                rightHead->next = NULL;
                break;
            }
            rightHead->next = leftnxt;

            head = leftnxt;
            rightHead = rightnxt;

            if(i == (cnt/2)-1) {
                head->next = NULL;
            }
        }
    }
};