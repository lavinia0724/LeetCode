// 2026/05/03
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 經典分堆問題: 分兩堆 + 差最小 → 背包找 total/2 → ans = total - 2 * best
        int total = accumulate(stones.begin(), stones.end(), 0);
        int target = total/2;

        vector<int> dp(target+1, 0);

        for(auto stone: stones){
            for(int j = target; j >= stone; --j){
                dp[j] = max(dp[j], dp[j-stone] + stone);
            }
        }
        return total - 2 * dp[target];
    }
};