// 2026/03/14
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> trailing(n);
        // 計算每一列尾巴連續 0 的數量 trailingZeros
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) cnt++;
                else break;
            }
            trailing[i] = cnt;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) { // 從 上到下安排列
            int need = n - i - 1; // 需要找第一個 trailingZeros[j] ≥ need
            int j = i;
            while (j < n && trailing[j] < need) j++;

            if (j == n) return -1; // 找不到所以回傳 -1

            // 把第 j 列往上 swap 到 i
            while (j > i) {
                swap(trailing[j], trailing[j - 1]);
                ans++;
                j--;
            }
        }

        return ans;
    }
};