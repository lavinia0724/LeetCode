// 2026/01/05
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long total = 0;
        int negCnt = 0;
        int mini = INT_MAX;

        for(auto row: matrix){
            for(int x: row){
                if(x < 0) negCnt++;
                total += abs(x);
                mini = min(mini, abs(x));
            }
        }

        if(negCnt & 1) total -= 2LL * mini;
        return total;
    }
};