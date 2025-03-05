// 2025/03/05 
class Solution {
    public:
        long long coloredCells(int n) {
            return 1 + 2 * (n - 1) * (long long)n; // 1 + 4 * ((n-1) * n) / 2
        }
    };