// 2025/02/12
class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            int maxSum = -1;
            unordered_map<int, set<int>> sumTable;
            for(auto item: nums){
                int tmp = item, tmpSum = 0;
                while(tmp > 0){
                    tmpSum += tmp % 10;
                    tmp /= 10;
                }
    
                if(sumTable.find(tmpSum) != sumTable.end()){
                    maxSum = max(maxSum, item + *sumTable[tmpSum].rbegin()); // *sumTable[tmpSum].rbegin() 因為 sumTable[tmpSum] 放的是 set，所以取 rbegin 是最大的值
                }
                sumTable[tmpSum].insert(item);
            }
            return maxSum;
        }
    };