// 2026/05/05
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL) return head;

        ListNode* now = head;
        int nodecnt = 0;
        while(now != NULL){
            nodecnt++;
            ListNode* nextnode = now->next;
            now = nextnode;
        }

        int newheadidx = nodecnt - (k % nodecnt);
        if(newheadidx == 0 || (k % nodecnt) == 0) return head;

        ListNode* orihead = head;
        now = head;
        for(int i = 0; i < nodecnt; ++i){
            ListNode* nextnode = now->next;

            if(i+1 == newheadidx) now->next = nullptr;
            if(i == newheadidx) head = now;
            if(i == nodecnt-1) now->next = orihead;

            now = nextnode;
        }
        return head;
    }
};