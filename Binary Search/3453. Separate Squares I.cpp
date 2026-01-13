// 2026/01/13
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 0, high = 0;
        for (auto& s : squares) {
            high = max(high, (double)s[1] + s[2]); // 所有正方形中最上面的邊在哪個 Y 軸上
        }

        // Binary Search on Y
        // 假設要找的線，是 Y = mid
        const double eps = 1e-6;
        while (high - low > eps) {
            double mid = (low + high) / 2.0;
            // below：所有正方形在 y < mid 的總面積; above：所有正方形在 y > mid 的總面積
            double above = 0, below = 0;

            for (auto& s : squares) {
                double y = s[1];
                double length = s[2];
                double area = length * length;

                if (y + length <= mid)  below += area;
                else if (y >= mid)  above += area;
                else { // 這個正方形跨越 Y = mid 這條線，要分開算上半下半 
                    double below_h = mid - y;
                    double above_h = y + length - mid;
                    below += below_h * length;
                    above += above_h * length;
                }
            }

            if (above > below)  low = mid;
            else high = mid;
        }
        return low;
    }
};