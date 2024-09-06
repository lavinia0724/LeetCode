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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> hashTable(nums.begin(), nums.end());

        ListNode* prev = NULL;
        ListNode* now = head;
        while(now != NULL){
            if(hashTable.count(now->val) > 0){
                if(prev != NULL) prev->next = now->next;
                else head = now->next;
            }
            else prev = now;
            
            now = now->next;
        }
        return head;
    }
};