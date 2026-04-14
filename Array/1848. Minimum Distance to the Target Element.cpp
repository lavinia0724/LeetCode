// 2026/04/13
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        for(int i = start; i < nums.size(); ++i){
            if(nums[i] == target) ans = min(ans, abs(i - start));
        }
        for(int i = start; i >= 0; --i){
            if(nums[i] == target) ans = min(ans, abs(i - start));
        }
        return ans;
    }
};