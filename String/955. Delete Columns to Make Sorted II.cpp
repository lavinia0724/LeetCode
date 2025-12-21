// 2025/12/21
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        // sorted[i] = true 表示 strs[i] <= strs[i+1] 已經確定
        vector<bool> sorted(n - 1, false);

        int ans = 0;
        for (int col = 0; col < m; col++) {
            bool needDelete = false;

            // 檢查這一 row 是否非遞增
            for (int row = 0; row < n - 1 && !needDelete; row++) {
                if (!sorted[row] && strs[row][col] > strs[row + 1][col]) {
                    needDelete = true;
                    break;
                }
            }

            if (needDelete) { // 直接刪這一 col
                ans++;
                continue;  
            }

            // 如不需刪除 col，更新哪些 row 到哪排已經確定是遞增的
            for (int row = 0; row < n - 1; row++) {
                if (!sorted[row] && strs[row][col] < strs[row + 1][col]) sorted[row] = true;
            }
        }
        return ans;
    }
};