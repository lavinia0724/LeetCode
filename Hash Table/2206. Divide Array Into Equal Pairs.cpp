// 2025/04/03
class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_map<int, int> mp;
            for(auto num: nums) mp[num]++;
    
            for(auto it = mp.begin(); it != mp.end(); ++it){
                if(it->second % 2 != 0) return false;
            }
            return true;
        }
    };