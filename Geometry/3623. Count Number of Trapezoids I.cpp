// 2025/12/02
class Solution {
public:
    static const long long MOD = 1000000007;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> mp;
        for(auto p: points) mp[p[1]]++; // 統計每個 y 有多少點

        long long ans = 0, prefixSum = 0;
        // 某個高度 y 上有 k 個點，能形成 C(k,2) 條邊
        for(auto &[y, k]: mp){ 
            if(k < 2) continue;

            // C k 取 2 組線段數
            long long ways = k * (k - 1) / 2;

            // (當前線段數) * (之前所有累積的線段數) = 新增的梯形數
            ans = (ans + ways * prefixSum) % MOD;
            prefixSum = (prefixSum + ways) % MOD;
        }
        return ans;
    }
};