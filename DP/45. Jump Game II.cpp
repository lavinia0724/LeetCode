// 2026/05/06
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        int maxipos = 0, ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j <= i + nums[i] && j < n; ++j){
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }
        return dp[n-1] == INT_MAX ? -1 : dp[n-1];
    }
};