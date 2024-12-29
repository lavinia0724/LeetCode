// 2024/12/29
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        vector<vector<int>> wordsAlphabet(words[0].size(), vector<int>(26, 0)); // 根據 string 有多長，來放每第 i 格在 words 之間有多少個各 alphabet

         // Step 1: Calculate frequency of each character at every index in "words".
        for(int i = 0; i < words.size(); ++i)
            for(int j = 0; j < words[0].size(); ++j) wordsAlphabet[j][words[i][j] - 'a']++; // 算各個 word 在這個 idx 有多少這個字母是在這個位置

        // Step 2: Initialize a DP table.
         vector<vector<long long int>> dp(words[0].size()+1, vector<long long int>(target.size()+1, 0));

        // 把所有 words 數量的 dp 頭都初始成 1
        for(int i = 0; i <= words[0].size(); ++i) dp[i][0] = 1;        

        // Step 3: Fill the DP table.
        for(int i = 1; i <= words[0].size(); ++i){ // i 是 current word index
            for(int j = 1; j <= target.size(); ++j){ // j 是 cirrent target index
                dp[i][j] = dp[i-1][j]; // 先把 上 的值複製下來

                int currentPosition = target[j - 1] - 'a';
                // 左上 是目前已經有多少種排列組合，乘上 現在這個字母在同一直排有多少個 word 可以選
                dp[i][j] += (dp[i-1][j-1] * wordsAlphabet[i-1][currentPosition]); // 左上 * 目前這個 current word index (要用前一格的值來繼續算)
                dp[i][j] %= 1000000007;
            }
        }

        return dp[words[0].size()][target.size()];
    }
};