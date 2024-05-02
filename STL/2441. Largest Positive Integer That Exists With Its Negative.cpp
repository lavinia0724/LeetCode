/* 2024/05/02 */
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 由小到大

        int right = nums.size() - 1, ans = -1;
        for(int left = 0; left < right;){
            if((0 - nums[left]) == nums[right]){
                ans = nums[right];
                break;
            }

            if(abs(nums[left]) < nums[right]) right--;
            else left++;
        }
        return ans;
    }
};