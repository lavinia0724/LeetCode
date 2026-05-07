// 2026/05/03
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1, 0);

        dp[0] = 1;

        for(int j = 1; j <= target; ++j){
            for(auto num: nums){
                if(j >= num) dp[j] += dp[j - num];
            }
        }
        
        return dp[target];
    }
};