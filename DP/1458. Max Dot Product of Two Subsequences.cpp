// 2026/01/08
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = nums1[i] * nums2[j];

                // 先直接看 nums1[i] * nums1[2] 有沒有比較好
                if (i > 0 && j > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + dp[i][j]);

                // 因為是可以跳過此數字不計的:
                // 不使用 nums1[i]，只看 nums1[0..i-1] 配 nums2[0..j]
                if (i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);

                // 不使用 nums1[2]，只看 nums2[0..j-1] 配 nums1[0..i]
                if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};