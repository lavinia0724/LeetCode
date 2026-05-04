// 2026/05/04
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n/2; ++j){
                swap(matrix[j][i], matrix[n-j-1][i]); // 先交換上下排
            }
        } 
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                swap(matrix[i][j], matrix[j][i]); // 交換對角線
            }
        }
    }
};