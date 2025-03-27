// 2025/03/27
class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int modCheck = grid[0][0] % x;
            // 首先先確認有沒有可能可以做到，判斷方法: 所有數字 % x 都會是同個值
            // 因為: a + ix == b + jx 的話，兩邊同 % x，會變成 a % x == b % x
            vector<int> nums;
            for(auto item: grid){ 
                for(auto num: item){
                    if(num % x != modCheck) return -1;
                    nums.emplace_back(num); // 順便為下一步驟做紀錄
                }
            }
    
            // 拿 grid 裡的 "中位數" 當每個數要做運算去變成的數字，因為所有數字到中位數的距離差會是最短的
            sort(nums.begin(), nums.end());
            int ans = 0, medium = nums[(nums.size()-1)/2];
            for(int i = 0; i < nums.size(); ++i){
                ans += abs(nums[i] - medium) / x;
            }
            return ans;
        }
    };