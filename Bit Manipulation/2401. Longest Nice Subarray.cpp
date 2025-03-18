// 2025/03/18
class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int maxi = 1;
            for(int i = 0; i < nums.size() - 1; ++i){
                int cnt = 1, prefixOR = nums[i];
                for(int j = i + 1; j < nums.size(); ++j){
                    if((nums[j] & prefixOR) == 0){
                        cnt++;
                        prefixOR |= nums[j];
                    }
                    else break;
                }
                maxi = max(maxi, cnt);
            }
            return maxi;
        }
    };
    
    /*
    ex: 2, 4, 3
    透過 prefixOR 可以記錄目前 subarray 2 OR 4 = 6, 6 and 3 != 0
    不然如果只判斷 4 and 3 會 = 0, 但 2 and 3 != 0 沒判斷到
    */