// 2025/04/26
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            long long cnt = 0, left = 0;
    
            deque<int> dqmini, dqmaxi;
            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] < minK || nums[i] > maxK){
                    dqmini.clear();
                    dqmaxi.clear();
                    left = i + 1;
                    continue;
                }
    
                while(!dqmini.empty() && nums[dqmini.back()] >= nums[i]) dqmini.pop_back();
                dqmini.push_back(i);
    
                while(!dqmaxi.empty() && nums[dqmaxi.back()] <= nums[i]) dqmaxi.pop_back();
                dqmaxi.push_back(i);
    
                if(nums[dqmini.front()] == minK && nums[dqmaxi.front()] == maxK){
                    int start = min(dqmini.front(), dqmaxi.front());
                    cnt += (start - left + 1);
                }
            }
            return cnt;
        }
    };