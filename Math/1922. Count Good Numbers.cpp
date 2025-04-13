// 2025/04/13
class Solution {
    public:
        int quickmul(int x, long long y){ // 快速冪
            int ret = 1, mul = x;
            while(y > 0){
                if(y % 2 == 1) ret = (long long) ret * mul % mod;
                mul = (long long) mul * mul % mod;
                y /= 2;
            }
            return ret;
        }
    
        int countGoodNumbers(long long n) {
            // even indices, 要偶數 0, 2, 4, 6, 8 有 5 種，一個字串偶數位總共有 (n + 1) / 2 格
            // odd  indices, 要質數 2, 3, 5, 7    有 4 種，一個字串奇數位總共有 n / 2 格
            return (long long)quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % mod;
        }
    
    private:
        static const int mod = 1000000007;
    };