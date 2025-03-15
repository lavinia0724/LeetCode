// 2025/03/15
class Solution {
    public:
        int minCapability(vector<int>& nums, int k) {
            int mini = 1, maxi = *max_element(nums.begin(), nums.end());
            while(mini < maxi){
                int mid = (mini + maxi) / 2;
                int theftHouse = 0;
                for(int i = 0; i < nums.size(); ++i){
                    if(nums[i] <= mid){ // mid 是在找一個數，使所有少於這個數的房子可被偷
                        theftHouse++;
                        ++i; // 這樣才會跳過下一間房子，使其不連續
                    }
                }
    
                if(theftHouse >= k) maxi = mid; // 如果偷太多間了，要縮小 right 的範圍
                else mini = mid + 1; // 反之，偷太少間
            }
            return mini;
        }
    };