// 2024/09/01
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m * n || original.size() % m != 0 || original.size() % n != 0) return {};

        vector<vector<int>> ans(m, vector<int>(n));
        int cnt = 0;
        for(int i = 0; i < original.size(); ++i){
            ans[cnt / n][cnt % n] = original[i];
            cnt++;
        }
        return ans;
    }
};