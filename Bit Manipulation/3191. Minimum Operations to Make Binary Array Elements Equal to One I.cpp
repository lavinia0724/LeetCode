// 2025/03/19
class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int cnt = 0;
            for(int i = 0; i < nums.size() - 2; ++i){ // 無條件只要遇到是 0 就翻轉他和後兩格成 1
                if(nums[i] == 0){
                    cnt++;
                    nums[i] = 1;
                    nums[i + 1] = (nums[i + 1] == 0) ? 1 : 0;
                    nums[i + 2] = (nums[i + 2] == 0) ? 1 : 0;
                }
            }
            return (nums[nums.size() - 1] == 1 && nums[nums.size() - 2] == 1) ? cnt : -1;
        }
    };