// 2026/01/18
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // sum of row r from col 0 to c-1
        vector<vector<int>> rowSum(m, vector<int>(n + 1, 0));
        // sum of col c from row 0 to r-1
        vector<vector<int>> colSum(m + 1, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
                colSum[i + 1][j] = colSum[i][j] + grid[i][j];
            }
        }

        int maxK = min(m, n);
        // k 是正方形邊長，從 最大可能 開始試
        for (int k = maxK; k >= 2; k--) {
            // 枚舉 i row, k col
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {

                    int target = rowSum[i][j + k] - rowSum[i][j];
                    bool ok = true;

                    // check rows
                    for (int r = i; r < i + k && ok; r++) {
                        int sum = rowSum[r][j + k] - rowSum[r][j];
                        if (sum != target) ok = false;
                    }

                    // check cols
                    for (int c = j; c < j + k && ok; c++) {
                        int sum = colSum[i + k][c] - colSum[i][c];
                        if (sum != target) ok = false;
                    }

                    // check diagonal
                    int diag1 = 0, diag2 = 0;
                    for (int d = 0; d < k; d++) {
                        diag1 += grid[i + d][j + d];
                        diag2 += grid[i + d][j + k - 1 - d];
                    }

                    if (diag1 != target || diag2 != target) ok = false;

                    if (ok) return k;
                }
            }
        }

        return 1;
    }
};