// 2026/05/03
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1, INT_MIN);

        dp[0] = 0;

        for(int num: nums){
            for(int j = target; j >= num; --j){
                dp[j] = max(dp[j], dp[j - num] + 1);
            }
        }
        return (dp[target] > 0) ? dp[target] : -1;
    }
};