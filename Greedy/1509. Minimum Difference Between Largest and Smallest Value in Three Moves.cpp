// 2024/07/03
class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) return 0;
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4 - i; ++j){
                if(i >= nums.size()-j-1) break;
                ans = min(ans, nums[nums.size()-j-1] - nums[i]);
            }
        }
        return ans;
    }
};