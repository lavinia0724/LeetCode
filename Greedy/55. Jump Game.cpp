// 2026/05/06
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        
        int maxipos = 0;
        for(int i = 0; i <= maxipos; ++i){
            maxipos = max(maxipos, i + nums[i]);
            if(maxipos >= n-1) return true;
        }
        return false;
    }
};