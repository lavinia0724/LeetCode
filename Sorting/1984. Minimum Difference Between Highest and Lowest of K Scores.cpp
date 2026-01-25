// 2026/01/25
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1) return 0;

        sort(nums.begin(), nums.end());

        int mini = INT_MAX;
        for(int i = 0; i + k - 1 < nums.size(); ++i){
            mini = min(mini, nums[i + k - 1] - nums[i]);
        }
        return mini;
    }
};