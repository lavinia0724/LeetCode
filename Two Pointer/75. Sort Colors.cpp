// 2024/06/13
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

// ------------------------------------------------------------------------

// 2025/05/23
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high){
            if(nums[mid] == 0) swap(nums[mid++], nums[low++]);
            else if(nums[mid] == 1) mid++;
            else swap(nums[mid], nums[high--]);
        }
    }
};