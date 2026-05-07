// 2026/05/07
class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        for(int i = 0; i < 32; ++i){
            if(n & 1) ans = (ans << 1) + 1;
            else ans <<= 1;

            n >>= 1;
        }
        return ans;
    }
};