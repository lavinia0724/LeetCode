// 2025/04/23
class Solution {
    public:
        int countLargestGroup(int n) {
            unordered_map<int, int> mp;
            for(int i = 1; i <= n; ++i){
                int num = i, tmp = 0;
                while(num > 0){
                    tmp += num % 10;
                    num /= 10;
                }
                mp[tmp]++;
            }
    
            int ans = 0, maxi = 0;
            for(auto item: mp){
                if(item.second > maxi){
                    maxi = item.second;
                    ans = 1;
                }
                else if(item.second == maxi) ans++;
            }
            return ans;
        } 
    };