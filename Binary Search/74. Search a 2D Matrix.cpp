// 2026/04/20
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() * matrix[0].size();
        int left = 0, right = n - 1;
        while(left <= right){
            int mid = (left + right) >> 1;
            int i = mid / matrix[0].size(), j = mid % matrix[0].size();

            if(matrix[i][j] == target) return true;

            if(matrix[i][j] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};