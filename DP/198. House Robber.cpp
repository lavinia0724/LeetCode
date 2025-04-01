// 2025/04/01
class Solution {
    public:
        int dpDFS(int idx, vector<int>& nums, vector<int>& dp){
            if(idx >= nums.size()) return 0;
            if(dp[idx] != -1) return dp[idx];
    
            int rob = nums[idx] + dpDFS(idx + 2, nums, dp);
            int notrob = dpDFS(idx + 1, nums, dp);
    
            return dp[idx] = max(rob, notrob);
        }
    
        int rob(vector<int>& nums) {
            vector<int> dp(nums.size(), -1);
            return dpDFS(0, nums, dp);
        }
    };