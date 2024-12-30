// 2024/12/30
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int dp[high+1]; // dp 裡放長度為 idx 時有多少可能組合 
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;

        int ans = 0;
        for(int i = 1; i <= high; ++i){ // idx 是目前 string 長度
            if(i - zero >= 0) dp[i] = (dp[i] + dp[i - zero]) % 1000000007;
            if(i - one  >= 0) dp[i] = (dp[i] + dp[i - one]) % 1000000007;

            if(i >= low) ans = (ans + dp[i]) % 1000000007;
        }

        return ans;
    }
};

/*
ex: low = 2, high = 3, zero = 1, one = 2

假設在 dp[5] 這格，尾數必為 0 或 11
尾數為 0，代表 dp[5] 可以是所有 dp[4] 的可能組合尾巴加個 0
尾數為 1，代表 dp[5] 可以是所有 dp[3] 的可能組合尾巴加 11

因此 dp[5] = dp[4] + dp[3]，也就是 dp[5 - zero] + dp[5 - one]

*/
