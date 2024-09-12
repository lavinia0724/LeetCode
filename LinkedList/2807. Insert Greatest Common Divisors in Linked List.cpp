// 2024/09/10
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
    int gcd(int a, int b){
        return (b == 0 ? a : gcd(b, a % b));
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL) return head;

        ListNode* prev = head;
        ListNode* now = head->next;

        while(now != NULL){
            ListNode* insertNum = new ListNode(gcd(prev->val, now->val));

            prev->next = insertNum;
            insertNum->next = now;

            prev = now;
            now = now->next;
        }
        return head;
    }
};