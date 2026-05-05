// 2026/05/05
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] == target) return mid;
            
            if(nums[mid] < nums[right]){  // 右半邊有序。因為找 binary search 需要在有排序的地方找，所以先找有序邊是必要的
                if(nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
            else{ // 左半邊有序
                if(nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};