// 2025/04/13
class Solution {
    public:
        double quickmul(double x, long long y){
            double ret = 1.0, mul = x;
            while(y > 0){
                if(y % 2 == 1) ret = ret * mul;
                mul = mul * mul;
                y /= 2;
            }
            return ret;
        }
        double myPow(double x, int n) {
            long long N = n;
            if(N < 0){ // 指數有可能是負數，轉換一下
                x = 1 / x;
                N = -N;
            }
            return quickmul(x, N);
        }
    };