// 2024/09/14
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = -1, continueMaxi = 0, ans = 0;
        for(int i = 0; i < nums.size(); ++i) maxi = max(maxi, nums[i]);

        bool contiguous = false;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == maxi && !contiguous) {
                continueMaxi = 1;
                contiguous = true;
            }
            else if(nums[i] == maxi && contiguous) continueMaxi++;

            if(nums[i] != maxi && contiguous) contiguous = false;
            ans = max(ans, continueMaxi);
        }

        return ans;
    }
};