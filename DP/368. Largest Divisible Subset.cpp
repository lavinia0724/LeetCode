// 2025/04/06
class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            vector<int> dp(nums.size(), 1), prev(nums.size(), -1);
            sort(nums.begin(), nums.end());
    
            int maxi = 0;
            for(int i = 1; i < nums.size(); ++i){
                for(int j = 0; j < i; ++j){
                    if((nums[i] % nums[j] == 0) || (nums[j] % nums[i] == 0)){
                        if(dp[i] > (dp[j] + 1)) continue;
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
                if(dp[i] > dp[maxi]) maxi = i;
            }
    
            vector<int> ans;
            backtracking(maxi, ans, prev, nums);
    
            return ans;
        }
    
        void backtracking(int idx, vector<int>& ans, vector<int> prev, vector<int> nums){
            if(idx == -1) return;
            ans.emplace_back(nums[idx]);
            return backtracking(prev[idx], ans, prev, nums);
        }
    };