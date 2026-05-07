// 2026/05/07
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // text1 前 i 個字元 和 text2 前 j 個字元的 LCS 長度
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) { // 兩個字元相同
                    dp[i][j] = dp[i - 1][j - 1] + 1; // 代表這個字元可以加入共同 subsequence
                } else { // 代表這兩個字元不能一起選
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 不選 text1[i - 1] 或不選 不選 text2[j - 1]
                }
            }
        }

        return dp[m][n];
    }
};