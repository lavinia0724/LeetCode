// 2026/05/07
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans = 1;

        for (int x : nums) {
            int root = sqrt(x); // 去找 dp 裡面有沒有一個前一個數字 root，使得 root * root == x

            if (1LL * root * root == x && dp.count(root)) { // x 是 root 的平方，而且 root 前面出現過，可以接成 root -> x
                dp[x] = max(dp[x], dp[root] + 1);
            } else { // 如果 x 不能接在任何前面的數字後面，那它至少自己可以是一條長度 1 的序列
                dp[x] = max(dp[x], 1);
            }

            ans = max(ans, dp[x]);
        }

        return ans >= 2 ? ans : -1;
    }
};