// 2024/09/06
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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int sizeCnt = 0;
        ListNode* now = head;
        while(now != NULL){
            sizeCnt++;
            now = now->next;
        }

        if(sizeCnt <= 1) return NULL;

        int mid = sizeCnt / 2;
        now = head;
        for(int i = 0; i < mid; ++i){
            if(i != mid-1) {
                now = now->next;
                continue;
            }

            now->next = now->next->next;
        }
        return head;
    }
};