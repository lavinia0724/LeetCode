// 2024/10/01
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dictionarySet(dictionary.begin(), dictionary.end());
        vector<int> dp(s.size() + 1, 0);

        for(int start = s.size() - 1; start >= 0; --start){
            dp[start] = dp[start + 1] + 1;
            for(int end = start; end < s.size(); ++end){
                auto now = s.substr(start, end - start + 1);
                if(dictionarySet.count(now)) dp[start] = min(dp[start], dp[end + 1]);
            }
        }

        return dp[0];
    }
};

/*
s: leetscode
dp:
l e e t s c o d e
0 0 0 0 0 0 0 0 1, dp[start] = dp[start + 1] + 1;
0 0 0 0 0 0 0 2 1, dp[start] = dp[start + 1] + 1;
0 0 0 0 0 0 3 2 1, dp[start] = dp[start + 1] + 1;

--> now = "code"
because dp[start] = 1, dp[end + 1] = 0 --> dp[start] = 0
0 0 0 0 0 0 3 2 1 

0 0 0 0 1 0 3 2 1, dp[start] = dp[start + 1] + 1;
0 0 0 2 1 0 3 2 1, dp[start] = dp[start + 1] + 1; 
0 0 3 2 1 0 3 2 1, dp[start] = dp[start + 1] + 1;
0 4 3 2 1 0 3 2 1, dp[start] = dp[start + 1] + 1;

--> now = "leet"
because dp[start] = 1, dp[end + 1] = dp['s'] = 1 --> dp[start] = 1
1 4 3 2 1 0 3 2 1

return 1
*/