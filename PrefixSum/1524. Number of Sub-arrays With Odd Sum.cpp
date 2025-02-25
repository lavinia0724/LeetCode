// 2025/02/25
class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            const int MOD = 1e9 + 7;
            int ans = 0, prefixSum = 0;
            int oddCnt = 0, evenCnt = 1; // sum(0) 即是 even
            for(int num: arr){
                prefixSum += num;
    
                if(prefixSum & 1){ // prefixSum 是 odd
                    ans += evenCnt; // 因為 prefixSum 是奇數，如果想要有其他 num 的子奇數陣列，只能是目前此 num ~ 之前湊出偶數 prefixSum 的位置的數量
                    oddCnt++; // odd 組合數量增加
                }
                else{
                    ans += oddCnt; // 反之
                    evenCnt++;
                }
                ans %= MOD;
            }
            return ans;
        }
    };