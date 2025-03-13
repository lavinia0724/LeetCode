// 2025/03/13
class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int left = 0, right = queries.size();
            if(!binarySearch(nums, queries, right)) return -1; // 先試 k = right，如果連所有 query 都跑一次都沒能找到，直接回傳-1
    
            while(left <= right){
                int mid = (left + right) / 2;
                if(binarySearch(nums, queries, mid)){ // 用 binarySearch 搜尋 k 
                    right = mid - 1;
                }
                else left = mid + 1;
            }
            return left;
        }
    
        bool binarySearch(vector<int>& nums, vector<vector<int>>& queries, int k){
            vector<int> diffArr(nums.size() + 1);
            for(int queryIdx = 0; queryIdx < k; ++queryIdx){
                int start = queries[queryIdx][0], end = queries[queryIdx][1], val = queries[queryIdx][2];
                diffArr[start] += val; // 從這個 start 開始等等 sum 會加一次 val
                diffArr[end + 1] -= val; // 直到 end + 1 sum 要減一次 val，代表這 query 區間結束
            }
    
            int sum = 0;
            for(int numIdx = 0; numIdx < nums.size(); ++numIdx){
                sum += diffArr[numIdx];
                if(sum < nums[numIdx]) return false; // 代表還要找更多的 query 讓 sum 更大，所以 return false 讓 k 更新成 left = mid + 1 更大
            }
            return true;
        }
    };