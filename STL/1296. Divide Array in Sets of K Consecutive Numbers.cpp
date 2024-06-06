// 2024/06/06
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> num;
        for(int i = 0; i < nums.size(); ++i){
            num[nums[i]]++;
        }

        auto ptr = num.begin();
        for(auto iter = num.begin(); iter != num.end(); ++iter){
            while(iter->second > 0){
                for(int i = 0; i < k; ++i){
                    int now = iter->first + i;
                    if(num[now] <= 0) return false;
                    num[now] -= 1;
                }
            }
        }  

        return true;
    }
};