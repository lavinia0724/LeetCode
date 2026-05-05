// 2026/05/05
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return {-1, -1};

        int left = 0, right = n - 1;

        while(left < right){ // 找最小可行解
            int mid = left + (right - left) / 2;

            if(nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        int firstpos = left;
        if(nums[firstpos] != target) firstpos = -1;

        left = 0, right = n - 1;
        while(left < right){ // 找最大可行解
            int mid = left + (right - left + 1) / 2;

            if(nums[mid] <= target) left = mid;
            else right = mid - 1;
        }
        int lastpos = left;
        if(nums[lastpos] != target) lastpos = -1;

        return {firstpos, lastpos};
    }
};