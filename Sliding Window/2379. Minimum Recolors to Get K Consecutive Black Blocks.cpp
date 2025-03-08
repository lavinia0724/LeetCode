// 2025/03/08
class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int mini = INT_MAX;
            int slidingWindowBCnt = 0;
            for(int i = 0; i < k; ++i) if(blocks[i] == 'B') slidingWindowBCnt++;
            mini = min(mini, k - slidingWindowBCnt);
            if(mini == 0) return 0;
    
            for(int j = k; j < blocks.size(); ++j){
                if(blocks[j] == 'B') slidingWindowBCnt++;
                if(blocks[j-k] == 'B') slidingWindowBCnt--;
                mini = min(mini, k - slidingWindowBCnt); 
            }
            return mini;
        }
    };