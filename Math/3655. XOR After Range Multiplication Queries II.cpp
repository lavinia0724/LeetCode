// 2026/04/09
class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long r = 1;
        while (b) {
            if (b & 1) r = r * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return r;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n) + 1;
        // B：sqrt decomposition 的閾值，用來分成 小 k 和 大 k。
        // 小 k → k < B → 透過「差分 + residue 分組」處理。
        // 大 k → k ≥ B → 直接暴力做，因為每次更新次數 ≤ n / k ≤ √n。

        // small k: 差分表
        vector<vector<vector<int>>> diff(B);

        for (int k = 1; k < B; k++) {
            diff[k].resize(k);
            for (int r = 0; r < k; r++) {
                int len = (n - r + k - 1) / k;
                diff[k][r].assign(len + 1, 1); // 差分初始化為乘法單位元
            }
        }

        // 處理 queries
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k < B) {
                // 小 k：
                // 用差分來記錄乘法：
                // diff[k][rem][L] *= v
                // diff[k][rem][R+1] *= inv(v) → 代表區間結束後要「還原」乘法
                // 這樣一個 query 可以在 O(1) 操作內完成對該 residue class 的區間乘法
                int rem = l % k;

                int L = (l - rem) / k;
                int R = (r - rem) / k;

                diff[k][rem][L] = 1LL * diff[k][rem][L] * v % MOD;
                if (R + 1 < diff[k][rem].size()) {
                    long long inv = modPow(v, MOD - 2);
                    diff[k][rem][R + 1] = 1LL * diff[k][rem][R + 1] * inv % MOD;
                }
            } else {
                // 大 k 直接暴力
                for (int i = l; i <= r; i += k) {
                    nums[i] = (long long)nums[i] * v % MOD;
                }
            }
        }

        // 套用 small k
        for (int k = 1; k < B; k++) {
            for (int r = 0; r < k; r++) {
                long long cur = 1;
                int len = diff[k][r].size() - 1;

                for (int j = 0; j < len; j++) {
                    cur = cur * diff[k][r][j] % MOD;
                    int idx = r + j * k;
                    if (idx < n) {
                        nums[idx] = (long long)nums[idx] * cur % MOD;
                    }
                }
            }
        }

        // XOR
        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};