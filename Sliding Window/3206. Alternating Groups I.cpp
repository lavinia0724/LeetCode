// 2025/03/09
class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors) {
            int n = colors.size();
                colors.insert(colors.end(), colors.begin(), colors.end());
                int slidingWindowCheck = 1;
                for(int i = 1; i < 3; ++i){
                    if(colors[i] != colors[i-1]) slidingWindowCheck++;
                    else slidingWindowCheck = 1;
                }
        
                int ans = 0;
                if(slidingWindowCheck == 3) ans++;
        
                for(int i = 3; i < n + 3 - 1; ++i){
                    if(colors[i] != colors[i-1]){
                        slidingWindowCheck++;
                        if(slidingWindowCheck >= 3) ans++;
                    }
                    else slidingWindowCheck = 1;
                }
                return ans;
        }
    };