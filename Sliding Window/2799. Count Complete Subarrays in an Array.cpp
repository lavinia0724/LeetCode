// 2025/04/29
class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            unordered_map<int, int> mp, numCnt;
            for(auto num: nums) mp[num]++;
            int distinctElement = mp.size();
    
            int ans = 0, left = 0;
            for(int right = 0; right < nums.size(); ++right){
                numCnt[nums[right]]++;
    
                while(!numCnt.empty() && numCnt.size() == distinctElement && left <= right){
                    ans += (nums.size() - right);
    
                    numCnt[nums[left]]--;
                    if(numCnt[nums[left]] == 0) numCnt.erase(nums[left]);
                    left++;
                }
            }
            return ans;
        }
    };