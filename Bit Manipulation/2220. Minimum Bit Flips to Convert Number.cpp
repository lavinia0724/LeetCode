// 2024/09/11
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorBits = start ^ goal;
        int ans = 0;
        while(xorBits > 0){
            if(xorBits & 1) ans++;
            xorBits >>= 1;
        }
        return ans;
    }
};