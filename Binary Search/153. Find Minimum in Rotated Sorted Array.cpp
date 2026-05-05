// 2026/05/05
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right]) right = mid; // mid 可能是最小值，或最小值在左邊
            else left = mid + 1; // mid 在左半段大值區，最小值一定在右邊 
        }
        return nums[left];
    }
};