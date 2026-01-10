// 2026/01/10
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // 字元相同，那要保留這個字元
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + (int)s1[i - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 字元不相同，那看要選擇 不用 s1[i-1] 不用 s1[i-1]
            }
        }

        int sum = 0; // 計算 s1 和 s2 的 ASCII 總和
        for (char c : s1) sum += c; 
        for (char c : s2) sum += c;
        
        return sum - 2 * dp[n][m];
    }
};