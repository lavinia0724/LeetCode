// 2025/02/02
class Solution {
public:
    bool check(vector<int>& nums) {
        int checkPos = -1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < nums[i-1]){
                if(checkPos != -1) return false;
                checkPos = i;
            }
        }

        if(checkPos == -1) return true;
        if(checkPos != -1 && nums[0] >= nums[nums.size()-1]) return true;
        return false;
    }
};