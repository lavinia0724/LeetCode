// 2024/08/21
class Solution {
public:
    int strangePrinter(string s) {
        s = removeDuplicates(s); // 把 s 中連續的字元去掉
        int n = s.size();

        vector<vector<int>> dp(n, vector<int> (n, -1));
        return minimumTurns(0, n - 1, s, dp);
    }

    int minimumTurns(int start, int end, string& s, vector<vector<int>>& dp){
        if(start > end) return 0; // 如果 s 是 empty string 直接回傳

        if(dp[start][end] != -1) return dp[start][end]; // 如果已經計算過了，直接回傳

        int minTurns = 1 + minimumTurns(start + 1, end, s, dp); // worst case: print each character separately

        // 試著去找 matching characters 區間
        for(int k = start + 1; k <= end; ++k){
            if(s[k] == s[start]){
                // 當找到相同字母時，以他為左、右做分割，遞迴下去找其他區間做 dp
                int turnsWithMatch = minimumTurns(start, k - 1, s, dp) + minimumTurns(k + 1, end, s, dp);
                minTurns = min(minTurns, turnsWithMatch);
            }
        }
        dp[start][end] = minTurns;

        return dp[start][end];
    }

    string removeDuplicates(string& s){
        string uniqueChars = "";
        for(int i = 0; i < s.size(); ++i){
            char now = s[i];
            if(uniqueChars.size() > 0 && now == uniqueChars[uniqueChars.size()-1]) continue;

            uniqueChars += now;
        }
        return uniqueChars;
    }
};

/*
遞迴走法:
start end
0 2
1 2
2 2
3 2
2 2
dp:
-1 -1 -1 
-1 -1 -1 
-1 -1 1 

1 2
dp:
-1 -1 -1 
-1 -1 2 
-1 -1 1 

0 1
1 1
2 1
1 1
dp:
-1 -1 -1 
-1 1 2 
-1 -1 1 

0 1
dp:
-1 2 -1 
-1 1 2 
-1 -1 1 

3 2
0 2
dp:
-1 2 2 
-1 1 2 
-1 -1 1 

*/