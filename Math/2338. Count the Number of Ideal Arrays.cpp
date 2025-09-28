// 2025/09/28
class Solution {
public:
    const int MOD = 1e9 + 7;
    long long int modpow(long long int a, long long int e){ // 快速冪
        long long int r = 1;
        while(e){
            if(e & 1) r = (r * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return r;
    }
    int idealArrays(int n, int maxValue) {
        vector<int> prime(maxValue + 1, 0);
        // 建質數表
        for(int i = 2; i <= maxValue; ++i){
            if(prime[i] == 0){
                for(int j = i; j <= maxValue; j+= i){
                    if(prime[j] == 0) prime[j] = i;
                }
            }
        }

        // 為了估算最大的質數冪次，用 2 的最大冪次來估算，因為最大可能 a + n - 1，所以這裡先 +n
        int maxExponent = (int)(log(maxValue) / log(2)) + n;// log2(maxValue)
        vector<long long int> factor(maxExponent + 1), ifactor(maxExponent + 1); // ifactor 是為了算模逆元
        factor[0] = 1;
        for(int i = 1; i <= maxExponent; ++i) factor[i] = factor[i-1] * i % MOD;
        
        // a^(MOD-1) ≡ 1 (mod MOD) --同除 a--> a^(MOD-2) ≡ a^(-1) (mod MOD), 所以 a 的模逆元就是 a^(MOD-2)
        ifactor[maxExponent] = modpow(factor[maxExponent], MOD - 2);
        
        for(int i = maxExponent; i >= 1; --i) ifactor[i-1] = ifactor[i] * i % MOD;

        // 組合公式: C A 取 B -> A! / B!(A-B)!
        auto combinefunc = [&](int A, int B) -> long long int{ // 我很不習慣這種 func 寫法，但該學一下了啦
            if(B < 0 || B > A) return 0;
            return factor[A] * ifactor[B] % MOD * ifactor[A - B] % MOD; // ifactor 的意思就相當於除法，因為模數運算 (mod MOD) 下，不能直接做除法
        };

        long long int ans = 0;
        for(int x = 1; x <= maxValue; ++x){ // 遍歷每個可能的結尾元素 x
            int v = x;
            vector<pair<int, int>> primes; // (prime, exponent)
            while(v > 1){ // 質因數分解
                int p = prime[v];
                if(p == 0) p = v; // v is prime (only happens if v==1), but keep safe

                int cnt = 0;
                while(v % p == 0){
                    v /= p;
                    ++cnt;
                }
                primes.emplace_back(p, cnt); // 真就在算每個 x 的所有質因數分解及每個質因數的指數，例如 20 = 2^2 * 5
            }
            long long int product = 1;
            for(auto &pe: primes){ // 計算不同排列數量
                int a = pe.second;
                // 這裡相當於 C(a + n - 1, a)
                // 每個質數的冪次可以在長度為 n 的序列中非減序列，假設某質數 p 的冪次是 a
                // 我們要在 n 個位置分配 a 個「質數 p」的指數；也就是「把 a 個相同的球放入 n 個盒子中，盒子可以為 0」，因此是 C(a + n - 1, a)，排列組合數學
                product = (product * combinefunc(a + n-1, a)) % MOD;
            }
            ans += product;
            if(ans >= MOD) ans -= MOD;
        }
        return (int)ans;
    }
};