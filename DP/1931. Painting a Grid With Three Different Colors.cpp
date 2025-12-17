// 2025/12/17
class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    void generateStates(int row, int m, vector<int>& current, vector<vector<int>>& states) {
        if (row == m) {
            states.push_back(current);
            return;
        }
        for (int c = 0; c < 3; c++) { // 遍歷三種可放顏色的可能性
            if (row > 0 && current[row - 1] == c) continue;
            current[row] = c;
            generateStates(row + 1, m, current, states); // DFS 遍歷可能性
        }
    }

    int colorTheGrid(int m, int n) {
        vector<vector<int>> states;
        vector<int> current(m, 0);

        // 遍歷三種可放顏色的可能性
        generateStates(0, m, current, states);

        // 算可能性 ok 的組合
        int S = states.size(); // 所有可能性有多少種
        vector<vector<int>> ok(S, vector<int>(S, 1));
        for (int i = 0; i < S; i++) { // 前一 row
            for (int j = 0; j < S; j++) { // 這一 row
                for (int r = 0; r < m; r++) { // 的這個 column 
                    if (states[i][r] == states[j][r]) { // 不能相同，如果相同就 = 0 (不 ok)
                        ok[i][j] = 0;
                        break;
                    }
                }
            }
        }

        // 算 DP
        vector<long long> dp(S, 1), newdp(S, 0);
        for (int col = 1; col < n; col++) {
            fill(newdp.begin(), newdp.end(), 0); // 清空成 0
            for (int i = 0; i < S; i++) { // 前一 row
                for (int j = 0; j < S; j++) { // 這一 row
                    if (ok[i][j]) { // 如果這兩 row 能組
                        newdp[j] = (newdp[j] + dp[i]) % MOD;
                    }
                }
            }
            dp.swap(newdp); // 把 newdp 算出來的結果存 dp 裡
        }

        long long ans = 0;
        for (long long v : dp) ans = (ans + v) % MOD;
        return ans;
    }
};