// 2026/02/03
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if(nums.size() <= 3) return false;

        int cnt = 0, increasCheck = (nums[1] > nums[0]);
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == nums[i-1]) return false;

            if(nums[i] > nums[i-1]){
                if(!increasCheck){
                    if(cnt != 1) return false;
                    increasCheck = 1;
                    cnt++;
                }
            }
            else{
                if(increasCheck){
                    if(cnt != 0) return false;
                    increasCheck = 0;
                    cnt++;
                }
            }
        }
        if(cnt == 2) return true;
        return false;
    }
};