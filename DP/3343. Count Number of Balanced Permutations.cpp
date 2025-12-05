// 2025/12/05
class Solution {
public:
    static const int MOD = 1000000007;

    long long modpow(long long a, long long e){
        long long r = 1;
        while(e){
            if(e & 1) r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return r;
    }

    long long inv(long long x){
        return modpow(x, MOD - 2);
    }

    int countBalancedPermutations(string num) {
        /*
        Balanced 條件：
        偶數位 sum_even = 奇數位 sum_odd
        -> sum_even − sum_odd = 0

        每個 digit（0~9）有出現次數 cnt[d]
        如果我們決定 digit d 在偶數位放了 even[d] 個
        那它在奇數位就要放 odd[d] = cnt[d] - even[d]

        Balanced 條件：
        Σ digit * even[d] − Σ digit * (cnt[d] − even[d]) = 0
        -> Σ (2 * digit) * even[d] = Σ digit * cnt[d]
        -> Σ digit * even[d] = (總和) / 2
        */
        string velunexorai = num;
        int n = num.size();
        vector<int> cnt(10, 0); // 10 個數字的各出現次數

        int totalSum = 0;
        for(char c : num){ // 計算 num 中各數字的出現次數
            cnt[c - '0']++;
            totalSum += (c - '0');
        }

        if(totalSum % 2 != 0) return 0;

        int target = totalSum / 2;
        int evenSlots = (n + 1) / 2;
        int oddSlots = n / 2;

        // fact[i] = i! (i 的階乘), invfact[i] = (i!)^{-1} mod M (i! 的模反元素)，因為題目需要計算排列數
        vector<long long> fact(n + 1), invfact(n + 1); 
        fact[0] = 1;
        for(int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
        invfact[n] = inv(fact[n]);
        for(int i = n - 1; i >= 0; i--) invfact[i] = invfact[i + 1] * (i + 1) % MOD;

        // 三維 dp 超難
        // dp[i][s] = 處理到 digit i（0~i），能否湊出和 s 的方法數（後面會乘排列數）
        vector<vector<long long>> dp(target + 1, vector<long long>(evenSlots + 1));
        dp[0][0] = 1;
        for(int d = 0; d <= 9; d++){
            int c = cnt[d];
            if(c == 0) continue;

            vector<vector<long long>> newdp(target + 1, vector<long long>(evenSlots + 1));
            for(int sum = 0; sum <= target; sum++){
                for(int used = 0; used <= evenSlots; used++){
                    long long ways = dp[sum][used];
                    if(!ways) continue;

                    for(int x = 0; x <= c; x++){
                        int nsum = sum + x * d;
                        int nused = used + x;
                        if(nsum > target || nused > evenSlots) break;
                        long long add = ways * invfact[x] % MOD * invfact[c - x] % MOD;
                        newdp[nsum][nused] = (newdp[nsum][nused] + add) % MOD;
                    }
                }
            }
            dp.swap(newdp);
        }

        long long ans = 0;
        for(int used = 0; used <= evenSlots; used++){
            long long ways = dp[target][used];
            if(!ways) continue;

            if(used != evenSlots) continue;
            long long res = ways * fact[evenSlots] % MOD * fact[oddSlots] % MOD;

            ans = (ans + res) % MOD;
        }
        return ans;
    }
};