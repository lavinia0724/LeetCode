// 2025/02/27
class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
            int maxLen = 0;
    
            for(int curr = 2; curr < arr.size(); ++curr){
                int start = 0;
                int end = curr - 1;
    
                while(start < end){
                    int sum = arr[start] + arr[end];
                    if(sum > arr[curr]) end--;
                    else if(sum < arr[curr]) start++;
                    else{
                        dp[end][curr] = dp[start][end] + 1;
                        maxLen = max(maxLen, dp[end][curr]);
                        end--;
                        start++;
                    }
                }
            }
    
            return maxLen == 0 ? 0 : maxLen + 2;
        }
    };
    
    /*
    arr = [1,2,3,4,5,6,7,8]
    
    curr = 2, start = 0, end = 2 - 1 = 1
    sum = arr[0] + arr[1] = 3
    sum == arr[curr] == 3
    dp[1][2] = dp[0][1] + 1 = 1
    end = 0, start = 1 break
    
    curr = 3, start = 0, end = 3 - 1 = 2
    sum = arr[0] + arr[2] = 4
    sum == arr[curr] == 4
    dp[2][3] = dp[0][2] + 1 = 1
    end = 1, start = 1 break
    
    curr = 4, start = 0, end = 4 - 1 = 3
    sum = arr[0] + arr[3] = 5
    sum == arr[curr] == 5
    dp[3][4] = dp[0][3] + 1 = 1
    end = 2, start = 1 
    
    
    ... 巴拉巴拉
    */