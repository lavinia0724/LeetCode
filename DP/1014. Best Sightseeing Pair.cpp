// 2024/12/27
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int> dp(values.size()); // 存從左到右後誰是以遍歷的最大值

        dp[0] = values[0] + 0;

        int maxi = 0;
        for(int i = 1; i < values.size(); ++i){ 
            maxi = max(maxi, dp[i-1] + values[i] - i); // 這裡 values[i] - i 是題目的 values[j] - j

            // 更新現在的最大左邊的值給下一層，看現在誰是最大的 values[i] + i
            dp[i] = max(dp[i-1], values[i] + i);
        }

        return maxi;
    }
};