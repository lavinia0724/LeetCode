// 2026/05/03
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);

        unordered_map<string, bool> mp;
        for(auto word: wordDict) mp[word] = true;

        dp[0] = true;
        
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= i; ++j){ // j 是看從 0~j 能不能切一刀，讓 0~j 和 j+1~i 都是在 wordDict 裡的字串
                // dp[j] = true 代表: 0~j 是一個在 wordDict 裡的字串
                // mp[s.substr(j, i+1-j)]: 去找 j+1~i 是不是 wordDict 裡的字串
                // 如果是，要更新的是 dp[i+1] 這格，代表的是在 0~i 之間的所有字串都是在 wordDict 裡的
                if(dp[j] && mp[s.substr(j, i+1-j)]) dp[i+1] = true;
            }
        }
        return dp[n];
    }
};