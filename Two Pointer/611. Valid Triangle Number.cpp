// 2025/09/26
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int num1 = 0; num1 < nums.size(); ++num1){
            for(int num2 = num1+1; num2 < nums.size(); ++num2){
                for(int num3 = nums.size() - 1; num3 > num2; --num3){
                    if(nums[num1] + nums[num2] > nums[num3]){
                        ans += (num3 - num2);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};