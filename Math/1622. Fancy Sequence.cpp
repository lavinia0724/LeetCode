// 2026/03/15
class Fancy {
public:
    static const long long MOD = 1000000007;
    vector<long long> seq;

    long long mul = 1;
    long long add = 0;

    long long modpow(long long a, long long b) { // 快速冪
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }


    Fancy() {
        
    }
    
    void append(int val) {
        long long inv = modpow(mul, MOD - 2);
        long long stored = ((val - add) % MOD + MOD) % MOD;
        stored = stored * inv % MOD;
        seq.push_back(stored);
    }
    /*
    假設現在 global transform 是：
    x → mul * x + add
    如果直接存 x，會錯，要存原始值（inverse），也就是：
    val = (x - add) * inv(mul)
    這樣之後：
    mul * val + add = x
    */
    
    void addAll(int inc) { // add = add + inc
        add = (add + inc) % MOD;
    }
    
    void multAll(int m) {
        mul = mul * m % MOD;
        add = add * m % MOD;
    }
    /*
    所有數：
    x → x * m
    目前：
    mul * x + add
    乘上 m：
    (mul * x + add) * m
    = (mul*m) x + (add*m)
    所以：
    mul = mul * m
    add = add * m
    */
    
    int getIndex(int idx) { // 如果存在：real = mul * stored[idx] + add，回傳：real % MOD
        if (idx >= seq.size()) return -1;
        long long val = (mul * seq[idx] + add) % MOD;
        return (int)val;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */