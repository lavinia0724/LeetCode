// 2025/04/25
class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            unordered_map<int, int> cnt;
            int prefixSum = 0;
            long long ans = 0;
            cnt[0] = 1;
            for(int i = 0; i < nums.size(); ++i){
                prefixSum += (nums[i] % modulo == k);
                ans += cnt[(prefixSum - k + modulo) % modulo];
                cnt[prefixSum % modulo]++;
            }
            return ans;
        }
    };
    
    /*
    nums = [3,2,4], modulo = 2, k = 1
    i = 0
    prefixSum += (3 % 2 == 1) = 1
    ans += cnt[(1 - 1 + 2) % 2] = cnt[0] = 0 + 1
    cnt[1 % 2] = cnt[1]++
    
    i = 1
    prefixSum += (2 % 2 != 1) = 1
    ans += cnt[(1 - 1 + 2) % 2] = cnt[0] = 1 + 1
    cnt[1 % 2] = cnt[1]++
    
    i = 2
    prefixSum += (4 % 4 != 1) = 1
    ans += cnt[(1 - 1 + 2) % 2] = cnt[0] = 2 + 1
    cnt[1 % 2] = cnt[1]++
    
    return ans = 3
    */