// 2025/12/10
class Solution {
public:
    static const int MOD = 1000000007;

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();

        // 如果有任何一個複雜度 <= complexity[0]（除了自己），不可能全部解鎖
        // 否則答案是 (n-1)! mod MOD
        // n−1 個東西，想排成一個順序，算式是 (n−1)! = (n−1) (n−2) ⋯ 2 * 1
        long long ans = 1;
        for (int i = 1; i < n; ++i) {
            if (complexity[i] <= complexity[0]) return 0;
            ans = (ans * i) % MOD;
        }
        return ans;
    }
};
