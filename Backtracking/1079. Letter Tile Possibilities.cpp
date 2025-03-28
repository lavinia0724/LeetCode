// 2025/03/28
class Solution {
    public:
        int numTilePossibilities(string tiles) {
            memset(used, false, sizeof(used));
    
            backtracking("", tiles);
    
            return sequence.size() - 1; // -1 是減掉被算進去的 "" 字串
        }
    
        void backtracking(string nowStr, string tiles){
            if(sequence.count(nowStr) != 0) return;
            sequence[nowStr] = 1;
    
            for(int i = 0; i < tiles.size(); ++i){
                if(!used[i]){
                    used[i] = true;
                    backtracking(nowStr + tiles[i], tiles);
                    used[i] = false;
                }
            }
            return;
        }
    
    private:
        bool used[7];
        unordered_map<string, int> sequence;
    };