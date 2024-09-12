// 2024/09/11
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
    int step[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int direction = 0, rowNow = 0, colNow = 0;
        ListNode* now = head;
        while(now != NULL){
            ans[rowNow][colNow] = now->val;

            if(now->next == NULL) break;

            int rowNext = rowNow + step[direction][0];
            int colNext = colNow + step[direction][1];
            if(rowNext >= m || rowNext < 0 || colNext >= n || colNext < 0 || ans[rowNext][colNext] != -1) {
                direction = (direction + 1) % 4;
                continue;
            }

            now = now->next;
            rowNow = rowNext;
            colNow = colNext;
        }
        return ans;
    }
};