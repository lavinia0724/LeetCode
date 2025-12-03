// 2025/12/03
struct PairHash{
    unsigned long long operator() (const pair<long long, long long>& p) const{
        // 利用 C++ 內建的 hash 函數將兩個 long long 轉成雜湊值並 XOR 結合
        return hash<long long>()(p.first) ^ hash<long long>()(p.second);
    }
};

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        if(n < 4) return 0;

        // 紀錄平行線段組合 (斜率 -> (截距 -> 數量))
        // 斜率 map: key=斜率{dy, dx}, val=vector<截距>
        unordered_map<pair<long long, long long>, vector<long long>, PairHash> slopemp;
        // 紀錄中點 (用於扣除平行四邊形)
        // Key: 兩倍中點座標 {sum_x, sum_y}, Value: 該中點對應的所有線段斜率
        unordered_map<pair<long long, long long>, vector<pair<long long, long long>>, PairHash> midPointmp;

        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                long long x1 = points[i][0], y1 = points[i][1];
                long long x2 = points[j][0], y2 = points[j][1];

                // 計算斜率並正規化同除最大公因數 g
                long long dy = y1 - y2;
                long long dx = x1 - x2;
                long long g = gcd(abs(dy), abs(dx));
                dy /= g;
                dx /= g;

                if(dx < 0 || (dx == 0 && dy < 0)){
                    dx = -dx;
                    dy = -dy;
                }

                // 計算截距常數 c = y*dx - x*dy (幾何意義：決定線的位置)
                // 若斜率相同且 c 相同，則共線
                long long c = y1 * dx - x1 * dy;
                slopemp[{dy, dx}].push_back(c);
                midPointmp[{x1 + x2, y1 + y2}].push_back({dy, dx});
            }
        }

        // 所有合法的平行線段對 (排除共線)
        long long parallelPairs = 0;
        for(auto& [slope, cnt]: slopemp){
            long long totalSeg = cnt.size();
            if(totalSeg < 2) continue;

            // 計算同一斜率下，共線的群組
            unordered_map<long long, int> collinearCnt;
            for(long long c: cnt) collinearCnt[c]++;

            long long invalidPairs = 0;
            for(auto& [c, cnt]: collinearCnt){
                if(cnt > 1) invalidPairs += (long long) cnt * (cnt - 1) / 2;
            } 

            // 該斜率的貢獻 = C(總數, 2) - sum(C(各共線群組, 2))
            long long totalPairs = totalSeg * (totalSeg - 1) / 2;
            parallelPairs += totalPairs - invalidPairs;
        }

        // 平行四邊形數量 (對角線互相平分)
        long long parallelograms = 0;
        for(auto& [mid, slopes]: midPointmp){
            long long total = slopes.size();
            if(total < 2) continue;

            unordered_map<pair<long long, long long>, int, PairHash> slopeCnt;
            for(auto& s: slopes) slopeCnt[s]++;

            long long sameSlopePairs = 0;
            for(auto& [s, cnt]: slopeCnt){
                if(cnt > 1) sameSlopePairs += (long long) cnt * (cnt - 1) / 2;
            }

            // 總對數 - 斜率相同的對數 = 真正的平行四邊形
            long long validPairs = total * (total - 1) / 2;
            parallelograms += validPairs - sameSlopePairs;
        }

        // 結果 = (平行對聯集) - (平行四邊形)
        return parallelPairs - parallelograms;
    }
};