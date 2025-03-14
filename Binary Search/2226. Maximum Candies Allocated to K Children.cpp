// 2025/03/14
class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            int maxicandies = 0;
            for(auto candy: candies) maxicandies = max(maxicandies, candy);
    
            int left = 0, right = maxicandies;
            while(left < right){
                int mid = (left + right + 1) / 2;
                if(checkCandies(candies, k, mid)) left = mid;
                else right = mid - 1;
            }
            return left;
        }
    
        bool checkCandies(vector<int>& candies, long long k, int numOfcandies){
            long long int candiesParts = 0; // candies 可以組成多少個 numOfcandies 數量的組合
            for(int i = 0; i < candies.size(); ++i){
                candiesParts += candies[i] / numOfcandies;
            }
            return candiesParts >= k; // 如果 > k 代表 left 還太小，還能往上找，如果 = k 那回去後迴圈也會結束 left = mid 然後回傳 left
        }
    };