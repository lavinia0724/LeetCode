// 2025/09/25
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size()+1, vector<int>(triangle.size()+1, INT_MAX));
        dp[0][0] = 0;
        for(int i = 1; i <= triangle.size(); ++i){
            for(int j = 1; j <= i; ++j){
                dp[i][j] = triangle[i-1][j-1] + min(dp[i-1][j-1], dp[i-1][j]); // dp 看左上和上上
            }
        }
        int mini = INT_MAX;
        for(int i = 1; i <= triangle.size(); ++i) mini = min(mini, dp[triangle.size()][i]);
        return mini;
    }
};