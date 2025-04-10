// 2025/04/10
class Solution {
    public:
        long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
            return count(finish, limit, s) - count(start - 1, limit, s);
        }
    
        long long count(long long finish, int limit, const string& suffix){
            string strfinish = to_string(finish);
            int prefixLength = strfinish.size() - suffix.size();
    
            if(prefixLength < 0) return 0;
    
            // dp i: prefixLength + 1 長度的可組的位數，每位數的 row 存兩個 col
            // [0]: 該位數有多少可能組合 * 他往後有多少可能組合
            // [1]: 如果 strfinish 最後幾位比 suffix 大，會多的那 1 種可能的所有可能
            vector<vector<long long>> dp(prefixLength + 1, vector<long long>(2, 0));
    
            dp[prefixLength][0] = 1;
            // 如果 strfinish 最後幾位比 suffix 大，會多 1 種可能，dp[prefixLength][1] 直接 = 1
            dp[prefixLength][1] = strfinish.substr(prefixLength) >= suffix ? 1: 0;
    
            for(int i = prefixLength - 1; i >= 0; --i){
                int now = strfinish[i] - '0';
    
                // limit + 1 因為 0 ~ limit
                dp[i][0] = (limit + 1) * dp[i + 1][0];
    
                if(now <= limit) dp[i][1] = (long long) now * dp[i + 1][0] + dp[i + 1][1];
                else dp[i][1] = (long long) (limit + 1) * dp[i + 1][0];
            }
            return dp[0][1];
        }
    };