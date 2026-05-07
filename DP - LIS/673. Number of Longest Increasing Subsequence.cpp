// 2026/05/07
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n, 1);
        vector<int> count(n, 1);

        int maxLen = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        count[i] = count[j]; // 更長就覆蓋數量
                    }
                    else if(len[j] + 1 == len[i]) count[i] += count[j]; // 一樣長就累加數量 (加上另一批同樣長度的LIS)
                }
            }
            maxLen = max(maxLen, len[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (len[i] == maxLen)  ans += count[i];
        }
        return ans;
    }
};