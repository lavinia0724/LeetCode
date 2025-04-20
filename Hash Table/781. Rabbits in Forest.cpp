// 2025/04/20
class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<int, int> mp;
            for(auto x: answers) mp[x]++;
    
            int total = 0;
            for(auto [x, num]: mp){
                total += (x + 1) * ceil(double(num) / (x + 1));
            }
            return total;
        }
    };