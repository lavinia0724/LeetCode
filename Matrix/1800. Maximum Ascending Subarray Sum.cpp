// 2025/02/04
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int tmpSum = nums[0], maxSum = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > nums[i-1]) tmpSum += nums[i];
            if(nums[i] <= nums[i-1]) tmpSum = nums[i];
            maxSum = max(maxSum, tmpSum);
        }
        return maxSum;
    }
};