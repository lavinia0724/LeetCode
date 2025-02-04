// 2025/02/03
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLongest = 1, nowLong = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > nums[i-1]){
                nowLong++;
                maxLongest = max(maxLongest, nowLong);
            }
            else nowLong = 1;
        }

        nowLong = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < nums[i-1]){
                nowLong++;
                maxLongest = max(maxLongest, nowLong);
            }
            else nowLong = 1;
        }

        return maxLongest;
    }
};