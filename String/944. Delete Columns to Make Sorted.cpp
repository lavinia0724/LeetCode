// 2025/12/21
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for(int col = 0; col < strs[0].size(); ++col){
            int cnt = 1;
            for(int row = 1; row < strs.size() && cnt; ++row){
                if(strs[row][col] < strs[row-1][col]) cnt = 0;
            }
            if(!cnt) ans++;
        }
        return ans;
    }
};