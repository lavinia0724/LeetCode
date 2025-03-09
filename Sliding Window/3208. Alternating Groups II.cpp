// 2025/03/09
class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
            colors.insert(colors.end(), colors.begin(), colors.end());
            int slidingWindowCheck = 1;
            for(int i = 1; i < k; ++i){
                if(colors[i] != colors[i-1]) slidingWindowCheck++;
                else slidingWindowCheck = 1;
            }
    
            int ans = 0;
            if(slidingWindowCheck == k) ans++;
    
            for(int i = k; i < n + k - 1; ++i){
                if(colors[i] != colors[i-1]){
                    slidingWindowCheck++;
                    if(slidingWindowCheck >= k) ans++;
                }
                else slidingWindowCheck = 1;
            }
            return ans;
        }
    };