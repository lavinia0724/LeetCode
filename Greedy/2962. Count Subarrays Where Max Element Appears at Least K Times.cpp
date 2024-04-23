/* 2024/04/23 */
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int ans = 0;
        int cnt = 0, maxi = 0;
        for(int i = 0; i < nums.size(); ++i){
            maxi = max(maxi, nums[i]);
        }
        
        int left = 0, right = 0;
        bool visited[nums.size()];
        memset(visited, false, sizeof(visited));
        for(left = 0; left < nums.size(); ++left){
            for(; right < nums.size(); ++right){
                if(cnt == k){
                    ans += nums.size() - right;
                    break;
                }
                if(nums[right] == maxi && !visited[right]){
                    visited[right] = true;
                    cnt++;
                    if(cnt == k){
                        ans += nums.size() - right;
                        break;
                    }
                }
            }
            if(nums[left] == maxi) cnt--;
        }
        return ans;
    }
};