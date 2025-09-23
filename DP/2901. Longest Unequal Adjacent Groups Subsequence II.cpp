// 2025/09/23
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<int> dp(groups.size(), 1); // 每個字至少能自己成為長度 1 的 subsequence
        vector<int> prev(groups.size(), -1); // 前一個節點記錄
        int maxIndex = 0;
        for (int i = 1; i < words.size(); i++) { // 枚舉每兩兩 word 之間的可能性
            for (int j = 0; j < i; j++) {
                if (hammingDist(words[i], words[j]) == 1 && dp[j] + 1 > dp[i] && groups[i] != groups[j]) {
                    dp[i] = dp[j] + 1; // 更新「以 word[i] 結尾的最長長度」
                    prev[i] = j;       // 記錄前一個字是 word[j]，方便回溯整條鏈
                }
            }
            if (dp[i] > dp[maxIndex]) maxIndex = i;
        }

        vector<string> ans;
        for (int i = maxIndex; i >= 0; i = prev[i]) // 逆推回去
            ans.emplace_back(words[i]);
        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool hammingDist(string& s1, string& s2) {
        if (s1.size() != s2.size()) return false;
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            diff += s1[i] != s2[i];
            if (diff > 1) return false;
        }
        return diff == 1;
    }
};

/*
1. words[i]
代表第 i 個單字（或節點）
程式是把每個單字當作一個「節點」去做動態規劃

2. groups[i]
表示這個單字屬於哪一個組

dp[i] 的定義是「以第 i 個單字為結尾的最長鏈長度」
外層迴圈 for (int i = 1; i < groups.size(); i++)，就是在逐一考慮「假設鏈的結尾是第 i 個單字」的情況
*/