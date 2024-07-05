/** 2024/07/05
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstCritical = 0, lastCritical = -1;
        int prevCritical = 0;
        vector<int> ans({-1, -1});

        ListNode* prev = head;
        ListNode* now = head;
        int nowPtr = 0;
        while(now->next != nullptr){
            if((prev->val < now->val && now->next->val < now->val) || (prev->val > now->val && now->next->val > now->val)){
                if(firstCritical == 0) firstCritical = nowPtr;
                else{
                    lastCritical = nowPtr;
                    ans[1] = lastCritical - firstCritical;
                }

                if(prevCritical == 0) prevCritical = nowPtr;
                else{
                    if(ans[0] != -1) ans[0] = min(ans[0], (nowPtr - prevCritical));
                    else ans[0] = nowPtr - prevCritical;
                    prevCritical = nowPtr;
                }
            }
            prev = now;
            now = now->next;
            nowPtr++;
        }

        return ans;
    }
};