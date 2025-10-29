// 2025/10/29
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0, ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0){
                if(totalSum - leftSum == leftSum) ans += 2;
                else if(abs((totalSum - leftSum) - leftSum) == 1) ans++;
            }
            leftSum += nums[i];
        }
        return ans;
    }
};