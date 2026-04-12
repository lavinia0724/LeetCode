// 2026/04/13
class Solution {
public:
    int getDist(int a, int b) { // 曼哈頓距離
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        const int INF = 1e9;
        
        vector<vector<int>> dp(n, vector<int>(26, INF));
        for (int j = 0; j < 26; j++) dp[0][j] = 0;
        for (int i = 1; i < n; i++) {
            int prev = word[i - 1] - 'A';
            int cur = word[i] - 'A';

            for (int j = 0; j < 26; j++) {
                // 用原本在 prev 的那根手指去按 cur
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + getDist(prev, cur));

                // 用原本在 j 的那根手指去按 cur
                dp[i][prev] = min(dp[i][prev], dp[i - 1][j] + getDist(j, cur));
            }
        }

        int ans = INF;
        for (int j = 0; j < 26; j++) ans = min(ans, dp[n - 1][j]);
        return ans;
    }
};