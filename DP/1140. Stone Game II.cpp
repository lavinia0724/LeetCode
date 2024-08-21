// 2024/08/20
class Solution {
public:
    // s 是從第幾個元素開始取
    int solve(int s, int M, vector<int>& piles, vector<vector<int>>& cache){
        const int n = piles.size();
        if(s >= n) return 0;

        M = min(M, n);
        if(cache[s][M] > 0) return cache[s][M];
        if(s + 2 * M >= n) return cache[s][M] = accumulate(begin(piles) + s, end(piles), 0);

        int best = INT_MIN;
        int now = 0;
        for(int x = 1; x <= 2 * M; ++x){
            now += piles[s + x - 1];
            best = max(best, now - solve(s + x, max(x, M), piles, cache));
        }
        cache[s][M] = best;

        return cache[s][M];
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> cache(piles.size(), vector<int> (piles.size() + 1));

        int total = accumulate(begin(piles), end(piles), 0); // accumulate 計算 begin 到 end 裡所有的值，並累加到第三個參數 0 上
        return (total + solve(0, 1, piles, cache)) / 2;
    }
};