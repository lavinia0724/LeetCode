// 2025/05/14
class Solution {
public:
    const int mod = 1e9 + 7;

    vector<vector<int>> multiply(const vector<vector<int>>& powerResult, const vector<vector<int>>& powerBase) {
        int n = powerResult.size(); // n == 26， powerResult 是快速冪的 result；powerBase 是快速冪的 base
        vector<vector<int>> result(n, vector<int>(n, 0));
        for (int chr = 0; chr < n; ++chr)
            for (int to = 0; to < n; ++to)
                for (int from = 0; from < n; ++from)
                    result[chr][from] = (result[chr][from] + 1LL * powerResult[chr][to] * powerBase[to][from]) % mod;
        return result;
    }

    // 快速冪
    vector<vector<int>> power(vector<vector<int>> base, int exp) {
        vector<vector<int>> result(base.size(), vector<int>(base.size(), 0));
        for(int i = 0; i < base.size(); ++i) result[i][i] = 1; // from 自己 to 自己一定是 1

        while (exp > 0) { // base 是 from to 的轉移矩陣；result 是每個字母做快速冪的矩陣，是每個字母到每個字母的快速冪後的結果
            if (exp & 1) result = multiply(result, base);
            base = multiply(base, base);
            exp /= 2;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<int> cnt(26);
        for (char c : s) cnt[c - 'a']++;

        // 建立 26x26 轉移矩陣
        vector<vector<int>> M(26, vector<int>(26, 0));
        for (int from = 0; from < 26; ++from) {
            for (int j = 1; j <= nums[from]; ++j) {
                int to = (from + j) % 26;
                M[to][from] = (M[to][from] + 1) % mod;
            }
        }

        // 快速冪 M^t
        vector<vector<int>> Mt = power(M, t);

        // 套用 M^t * cnt: 因為做 t 次轉換，所以 M^t，而每次都是 cnt_next = M × cnt_current，所以 final = M^t * cnt
        vector<int> final(26);
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                final[i] = (final[i] + 1LL * Mt[i][j] * cnt[j]) % mod;

        int ans = 0;
        for (int val : final) ans = (ans + val) % mod;
        return ans;
    }
};
