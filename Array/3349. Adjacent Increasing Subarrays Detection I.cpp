// 2025/10/18
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k == 1 && nums.size() >= 2) return true;
        int cnt1 = 1, cnt2 = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > nums[i-1]){
                if(cnt2) cnt2++;
                else cnt1++;
            }
            else{
                if(cnt1 >= k){
                    cnt2 = 1;
                }
                else if(cnt2 && cnt2 < k) cnt2 = 0;
                cnt1 = 1;
            }
            cout << nums[i] << " " << cnt1 << " " << cnt2 << endl;

            if(cnt1 == k + k) return true;
            if(cnt2 == k) return true;
        }
        return false;
    }
};D