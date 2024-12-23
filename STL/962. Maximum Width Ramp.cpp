// 2024/10/10
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> MonotonicStack; 
        MonotonicStack.push(0);
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < nums[MonotonicStack.top()]) MonotonicStack.push(i);
        }

        int ans = 0;
        for(int i = nums.size() - 1; i >= 0; --i){
            while(!MonotonicStack.empty() && nums[i] >= nums[MonotonicStack.top()]){
                ans = max(ans, i - MonotonicStack.top());
                MonotonicStack.pop();
            }
        }
        return ans;
    }
};