// 2026/04/19
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(left < right){
            int mid = (left + right) >> 1;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};