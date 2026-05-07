// 2025/04/07
class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int total = 0;
            for(auto num: nums) total += num;
    
            if(total % 2 != 0) return false;
            total /= 2;
    
            vector<bool> dp(total + 1, false);
            dp[0] = true; // 因為甚麼都不加 sum 一定為 0
            for(auto num: nums){
                for(int currSum = total; currSum >= num; --currSum){
                    dp[currSum] = dp[currSum] || dp[currSum - num]; // 去試有沒有可能達到 total 
                }
            }
            return dp[total];
        }
    };