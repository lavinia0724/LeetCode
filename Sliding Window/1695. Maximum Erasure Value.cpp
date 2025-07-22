// 2025/07/22
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int start = 0, sum = 0, maxi = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(mp.find(nums[i]) != mp.end()){
                if(mp[nums[i]] < start){
                    mp[nums[i]] = i;
                }
                else{
                    for(int j = start; j <= mp[nums[i]]; ++j) sum -= nums[j];
                    start = mp[nums[i]] + 1;
                    mp[nums[i]] = i;
                }
            }
            else mp[nums[i]] = i;
            sum += nums[i];
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};