// 2025/09/30
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            vector<int> newNums;
            for(int j = 0; j < nums.size()-1; ++j){
                newNums.emplace_back((nums[j] + nums[j+1]) % 10);
            }
            nums = newNums;
        }
        return nums[0];
    }
};