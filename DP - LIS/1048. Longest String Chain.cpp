// 2026/05/07
class Solution {
public:
    bool isPredecessor(const string& small, const string& large) {
        if (small.size() + 1 != large.size()) return false; // 每個 LIS 只能比前一個多一字元

        int i = 0, j = 0;
        int mismatch = 0;

        while (i < small.size() && j < large.size()) {
            if (small[i] == large[j]) { // 如果兩個字元一樣，代表這個位置可以對上
                i++;
                j++;
            } else { // 如果字元不一樣，代表可能是 large 多出來的那個字元
                mismatch++;

                // 注意這裡只移動 j，因為假設large[j] 是多出來的字元，把它跳過
                // small[i] 還要繼續跟 large 的下一個字元比較
                j++;

                if (mismatch > 1) return false; // 因為 large 只能比 small 多一個字元，多兩個以上都不行
            }
        }

        return true;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        vector<int> dp(n, 1);
        int ans = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (isPredecessor(words[j], words[i])) { // 如果 words[j] 可以接到 words[i] 前面
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};