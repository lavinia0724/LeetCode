// 2025/04/02
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long int ans = 0;
            for(int i = 0; i < nums.size()-2; ++i){
                for(int j = i + 1; j < nums.size()-1; ++j){
                    for(int k = j + 1; k < nums.size(); ++k){
                        long long int triplet = (long long int)(nums[i] - nums[j]) * (long long int)nums[k];
                        ans = max(ans, triplet);
                    }
                }
            }
    
            return ans;
        }
    };