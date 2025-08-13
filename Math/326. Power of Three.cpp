// 2025/08/13
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        return abs(double(log(n) / log(3)) - ceil(double(log(n) / log(3)))) < 1e-10;
    }
};