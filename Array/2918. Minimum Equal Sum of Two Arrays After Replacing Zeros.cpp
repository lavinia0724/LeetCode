// 2025/05/12
class Solution {
    public:
        long long minSum(vector<int>& nums1, vector<int>& nums2) {
            int cnt1 = 0, cnt2 = 0;
            long long numsum1 = 0, numsum2 = 0;
            for(auto num: nums1){
                if(num == 0) cnt1++;
                else numsum1 += num;
            }
            for(auto num: nums2){
                if(num == 0) cnt2++;
                else numsum2 += num;
            }
    
            if(numsum2 + cnt2 < numsum1 + cnt1){
                if(cnt2 == 0) return -1;
                return numsum1 + cnt1;
            }
            else if(numsum2 + cnt2 > numsum1 + cnt1){
                if(cnt1 == 0) return -1;
                return numsum2 + cnt2;
            }
            else{
                return numsum2 + cnt2;
            }
        }
    };