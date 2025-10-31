// 2025/10/31
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diffArr(nums.size() + 1, 0);
        for(auto& q: queries){
            int left = q[0], right = q[1];
            diffArr[left] += 1;
            if(right + 1 < nums.size()) diffArr[right + 1] -= 1;
        }

        int cover = 0;
        for(int i = 0; i < nums.size(); ++i){
            cover += diffArr[i];
            if(nums[i] > cover) return false;
        }
        return true;
    }
};