// 2025/08/09
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        return (ceil(log2(n)) == log2(n)); // 如果 ceil 無條件向上取整 log2 == log2 的結果，代表真的是 2 的指數倍，沒有小數點
    }
};