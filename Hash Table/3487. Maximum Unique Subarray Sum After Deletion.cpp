// 2025/07/26
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0, maxi = INT_MIN;
        for(auto num: nums){
            maxi = max(maxi, num);
            if(num <= 0) continue;
            if(mp.find(num) == mp.end()){
                ans += num;
                mp[num]++;
            }
        }
        return (ans == 0) ? maxi : ans;
    }
};