// 2025/09/27
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0.0;
        for(int i = 0; i < points.size() - 2; ++i){
            for(int j = i + 1; j < points.size() - 1; ++j){
                for(int k = j + 1; k < points.size(); ++k){
                    ans = max(ans, 0.5 * abs((points[j][0] - points[i][0]) * (points[k][1] - points[i][1]) - (points[j][1] - points[i][1]) * (points[k][0] - points[i][0])));
                }
            }
        }
        return ans;
    }
};

/*
Triangle Area = 1/2​ * ∣ (x2​−x1​)(y3​−y1​) − (y2​−y1​)(x3​−x1​) ∣
*/