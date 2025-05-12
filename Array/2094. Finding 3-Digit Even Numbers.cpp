// 2025/05/12
class Solution {
    public:
        vector<int> findEvenNumbers(vector<int>& digits) {
            vector<int> ans;
            unordered_map<int, int> mp;
            for(int i = 0; i < digits.size(); ++i){
                if(digits[i] == 0) continue;
                for(int j = 0; j < digits.size(); ++j){
                    if(i == j) continue;
                    for(int k = 0; k < digits.size(); ++k){
                        if(i == k || j == k) continue;
                        if(digits[k] & 1) continue;
                        mp[digits[i] * 100 + digits[j] * 10 + digits[k]]++;
                    }
                }
            }
    
            for(auto num: mp) ans.push_back(num.first);
    
            sort(ans.begin(), ans.end());
            return ans;
        }
    };