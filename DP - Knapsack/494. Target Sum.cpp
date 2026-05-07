// 2024/12/26
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target) > totalSum) return 0;

        vector<vector<int>> dp(nums.size(), vector<int>(2 * totalSum + 1, 0));

        dp[0][totalSum + nums[0]] += 1;
        dp[0][totalSum - nums[0]] += 1;

        for(int i = 1; i < nums.size(); ++i){
            for(int j = -totalSum; j <= totalSum; ++j){ // 就是把 -totalSum ~ totalSum 全跑一遍
                if(dp[i-1][j + totalSum] > 0){ // 代表以前有更新過
                    dp[i][j + totalSum + nums[i]] += dp[i-1][j + totalSum]; // 更新加上 nums[i] 的 dp 那格的值 (沒更新過就是把 dp[i-1][sum + totalSum] 以前更新過的那格的值給這格)
                    dp[i][j + totalSum - nums[i]] += dp[i-1][j + totalSum]; // 同理，只是是更新減掉 nums[i] 的 dp 那格的值
                }
            }
        }
        
        return dp[nums.size()-1][target + totalSum];
    }
};