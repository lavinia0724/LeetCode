// 2024/06/14
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        for(int i = 0; i < nums.size() && i <= right; ++i){
            if(nums[i] == 0){
                if(i != left) {
                    swap(nums[i], nums[left]);
                    --i;
                }
                left++;
            }
            else if(nums[i] == 2){
                if(i != right) {
                    swap(nums[i], nums[right]);
                    --i;
                }
                right--;
            }

        }
    }
};