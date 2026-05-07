// 2026/05/07
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);

        int ans = 2;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                int diff = nums[i] - nums[j];
                int prevLen = 1;
                if (dp[j].count(diff)) prevLen = dp[j][diff];

                dp[i][diff] = max(dp[i][diff], prevLen + 1); // 以 nums[i] 結尾，公差為 diff 的最長長度
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};