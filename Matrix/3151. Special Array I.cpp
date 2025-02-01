// 2025/02/01
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool flag = (nums[0] & 1);
        for(int i = 1; i < nums.size(); ++i){
            if(flag == (nums[i] & 1)) return false;
            flag = (nums[i] & 1);
        }
        return true;
    }
};