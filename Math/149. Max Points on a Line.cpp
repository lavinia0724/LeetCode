// 2026/05/04
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // 固定一個基準點 i，枚舉它和其他所有點 j 的斜率
        // 也就是枚舉每兩兩個點之間的斜率，然後去數在哪個點，和其他最多個點，有相同斜率

        int n = points.size();
        if(n <= 2) return n;

        int ans = 2;// 最少肯定就 2 點
        for(int i = 0; i < n; ++i){ // 基準點
            unordered_map<double, int> mp;
            int x1 = points[i][0], y1 = points[i][1];

            for(int j = i+1; j < n; ++j){
                int x2 = points[j][0], y2 = points[j][1];

                double slope;
                if(x2 - x1 == 0) slope = 1e9;
                else slope = 1.0 * (y2 - y1) / (x2 - x1); 

                mp[slope]++;
                ans = max(ans, mp[slope] + 1);
            }
        }
        return ans;
    }
};