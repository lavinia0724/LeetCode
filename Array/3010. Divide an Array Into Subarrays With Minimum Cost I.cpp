// 2026/02/01
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = 0;
        int mini1 = INT_MAX, mini2 = INT_MAX;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] <= mini1){
                mini2 = mini1;
                mini1 = nums[i];
            }
            else if(nums[i] <= mini2){
                mini2 = nums[i];
            }
        }
        return nums[0] + mini1 + mini2;
    }
};