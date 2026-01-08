// 2026/01/08
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        // 掃第一列、第一行，如果是 0 那就先記下整 row/col 都要是 0，之後每 row/col 的第 0 格用來記那 row/col 有沒有 0
        for (int j = 0; j < n; j++){
            if (matrix[0][j] == 0) firstRowZero = true;
        }
        for (int i = 0; i < m; i++){
            if (matrix[i][0] == 0) firstColZero = true;
        }

        // 用第一列、第一行來記
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 根據標記清零
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }

        // 處理第一列
        if (firstRowZero) {
            for (int j = 0; j < n; j++) matrix[0][j] = 0;
        }

        // 處理第一行
        if (firstColZero) {
            for (int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};