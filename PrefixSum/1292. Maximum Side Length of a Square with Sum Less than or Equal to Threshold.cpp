// 2026/01/19
class Solution {
public:
    // 檢查是否存在一個 k x k 的子矩陣，其總和 <= threshold
    bool check(int k, int m, int n, int threshold, vector<vector<int>>& prefixSum) {
        for (int i = k; i <= m; i++) {
            for (int j = k; j <= n; j++) {
                int sum = prefixSum[i][j] - prefixSum[i - k][j] - prefixSum[i][j - k] + prefixSum[i - k][j - k];
                if (sum <= threshold)  return true;
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        // 建立 prefix sum，大小 (m+1) x (n+1)
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = mat[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
            }
        }

        int left = 0, right = min(m, n);
        // Binary Search on answer
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (check(mid, m, n, threshold, prefixSum)) left = mid;
            else right = mid - 1;
        }

        return left;
    }
};