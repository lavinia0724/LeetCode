// 2025/10/30
class Solution {
public:
    int smallestNumber(int n) {
        return (n & (n - 1)) == 0 ? pow(2, ceil(log2(n)) + 1) - 1 : pow(2, ceil(log2(n))) - 1;
    }
};