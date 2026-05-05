// 2026/05/05
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left < right){
            int mid = left + ((right - left) >> 1);

            if(nums[mid] > nums[mid+1]) right = mid; // 下降趨勢：mid 可能是 peak，或 peak 在左邊
            else left = mid + 1; // 上升趨勢：mid 不可能是 peak，右邊一定有 peak
        }
        return left;
    }
};