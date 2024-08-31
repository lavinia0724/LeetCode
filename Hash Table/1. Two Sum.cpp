// 2024/08/31
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        for(int i = 0; i < nums.size(); ++i){
            hashTable[nums[i]] = i;
        }   

        for(int i = 0; i < nums.size(); ++i){
            if(hashTable.find(target - nums[i]) != hashTable.end() && hashTable[target - nums[i]] != i){
                return {i, hashTable[target - nums[i]]};
            }
        }
        return {};
    }
};