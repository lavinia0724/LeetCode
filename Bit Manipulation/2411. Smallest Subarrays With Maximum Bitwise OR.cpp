// 2025/07/29
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> lastSeen(32, -1);  // 每個 bit 最後出現的位置
        for (int i = n - 1; i >= 0; --i) {
            for (int b = 0; b < 32; ++b) {
                if (nums[i] & (1 << b)) {
                    lastSeen[b] = i;
                }
            }

            int maxReach = i;
            for (int b = 0; b < 32; ++b) {
                if (lastSeen[b] != -1) {
                    maxReach = max(maxReach, lastSeen[b]);
                }
            }
            ans[i] = maxReach - i + 1;
        }
        return ans;
    }
};
