// 2024/07/24
class Solution {
public:
    struct Num{
        int num;
        int mappingNum;
    };
    bool static cmp(Num a, Num b){
        return a.mappingNum < b.mappingNum;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        Num mappingNums[nums.size()];
        for(int i = 0; i < nums.size(); ++i){
            string str = to_string(nums[i]);
            for(int j = 0; j < str.size(); ++j){
                str[j] = mapping[str[j]-'0'] + '0';
            }
            mappingNums[i].num = nums[i];
            mappingNums[i].mappingNum = stoi(str); 
        }
        
        sort(mappingNums, mappingNums + nums.size(), cmp);

        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i) ans.emplace_back(mappingNums[i].num);

        return ans;
    }
};v om