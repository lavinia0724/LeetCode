// 2025/03/12
class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int neg = 0, pos = 0;
            for(auto num: nums){
                if(num > 0) pos++;
                else if(num < 0) neg++;
            }
            return max(pos, neg);
        }
    };