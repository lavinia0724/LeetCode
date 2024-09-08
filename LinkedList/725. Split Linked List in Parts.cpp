// 2024/09/08
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* now = head;
        int listSize = 0;
        while(now != NULL){
            listSize++;
            now = now->next;
        }

        int partSize = listSize / k;
        int greaterPartNum = listSize % k;
        
        vector<ListNode*> ans(k, NULL);
        now = head;
        for(int i = 0; i < k && now != NULL; ++i){
            ans[i] = now;
            
            int nowPartSize = partSize + (greaterPartNum-- > 0 ? 1 : 0);

            for(int j = 0; j < nowPartSize - 1; ++j) now = now->next;

            ListNode* next = now->next;
            now->next = NULL;
            now = next;
        } 
        return ans;
    }
};