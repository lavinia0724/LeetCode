// 2026/05/02
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false)); // dp[i][j] 代表 i~j 之間是回文

        int maxLen = 1, maxStart = 0;
        for(int len = 1; len <= n; ++len){ // 枚舉最常迴文字串長度
            for(int i = 0; i + len - 1 < n; ++i){
                int j = i + len - 1; // 每次找字串頭 i ~ 尾 j

                if(s[i] == s[j]){ // 當 s[i] == s[j]，檢查中間是否有可能是回文
                    if(len <= 2 || dp[i+1][j-1]){ // len <= 2 直接就是回文，或是檢查 i+1 ~ j-1 是不是回文
                        dp[i][j] = true;

                        if(maxLen < len){
                            maxLen = len;
                            maxStart = i;
                        }
                    }
                }
            }
        }
        return s.substr(maxStart, maxLen);
    }
};