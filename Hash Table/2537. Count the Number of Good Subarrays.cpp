// 2025/04/16
class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            int same = 0, right = -1;
            unordered_map<int, int> cnt;
            long long ans = 0;
            for(int left = 0; left < nums.size(); ++left){
                while(same < k && right + 1 < nums.size()){
                    ++right;
                    // right 從現在的 left 出發，一路去紀錄接下來的 nums 中每個數的 cnt，所以當已經過有相同數他就會 ++ 到那個數的 cnt，以此建立 pair
                    same += cnt[nums[right]]; 
                    ++cnt[nums[right]]; 
                }
    
                if(same >= k) ans += nums.size() - right; // 從 n ~ right 都可以組 subarray 的 right，然後 left 邊界就是現在的 left 所以不影響
    
                --cnt[nums[left]];
                same -= cnt[nums[left]]; // 如果 cnt[nums[left]] > 1 就會影響 same 所以要更新
            }
            return ans;
        }
    };