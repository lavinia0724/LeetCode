// 2026/05/02
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if(n + m != s3.size()) return false;
        
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false)); // dp[i][j] 代表 s1 的 i 個和 s2 的 j 個

        dp[0][0] = true;

        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= m; ++j){
                if(i > 0 && s1[i-1] == s3[i+j-1]){
                    dp[i][j] = dp[i][j] || dp[i-1][j]; // || 因為是 true or false 只要 dp[i-1][j] 和 dp[i][j-1] 有人是 true 就好
                }
                if(j > 0 && s2[j-1] == s3[i+j-1]){
                    dp[i][j] = dp[i][j] || dp[i][j-1]; // || 因為是 true or false 只要 dp[i-1][j] 和 dp[i][j-1] 有人是 true 就好
                }
            }
        }
        return dp[n][m];
    }
};