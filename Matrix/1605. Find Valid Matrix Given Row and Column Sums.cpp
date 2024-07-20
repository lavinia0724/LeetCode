// 2024/07/20
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> originMatrix(rowSum.size(), vector<int>(colSum.size(), 0));

        for(int i = 0; i < rowSum.size(); ++i){
            for(int j = 0; j < colSum.size(); ++j){
                originMatrix[i][j] = min(rowSum[i], colSum[j]);

                rowSum[i] -= originMatrix[i][j];
                colSum[j] -= originMatrix[i][j];
            }
        }
        
        return originMatrix;
    }
};
/*
數論 - 逆推 (參考 Editorial Approach 2: Space Optimized Greedy)
Example 1:
rowSum = [3, 8], colSum = [4, 7]

i = 0, j = 0
originMatrix = min(rowSum[i], colSum[j]) = min(3, 4) = 3
rowSum[i] -= 3, = 0
colSum[j] -= 3, = 1

i = 0, j = 1
originMatrix = min(rowSum[i], colSum[j]) = min(0, 7) = 0
rowSum[i] -= 0, = 0
colSum[j] -= 0, = 7

i = 1, j = 0
originMatrix = min(rowSum[i], colSum[j]) = min(8, 1) = 1
rowSum[i] -= 1, = 7
colSum[j] -= 1, = 0

i = 1, j = 1
originMatrix = min(rowSum[i], colSum[j]) = min(7, 7) = 7
rowSum[i] -= 7, = 0
colSum[j] -= 7, = 0

final
originMatrix = [[3, 0], [1, 7]]
*/