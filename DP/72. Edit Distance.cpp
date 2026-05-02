// 2026/05/02
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); // dp[i][j] = word1 前 i 個字，變成 word2 前 j 個字，最少要幾步

        /*
        三個方向更新 dp
        從上面來，代表 刪掉 word1 的第 i 個字
        從左上來，代表 把 word1的最後一個字換掉
        從左邊來，代表 插入 word2[j-1] 這個字
        */

        for(int i = 0; i <= n; ++i) dp[i][0] = i;
        for(int j = 0; j <= m; ++j) dp[0][j] = j;

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
            }
        }

        return dp[n][m];
    }
};