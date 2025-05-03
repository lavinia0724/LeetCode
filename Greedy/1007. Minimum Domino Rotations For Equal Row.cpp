// 2025/05/03
class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            for(int i = 1; i <= 6; ++i){
                bool check = false;
                int topRotate = 0, bottomRotate = 0;
                for(int j = 0; j < tops.size() && !check; ++j){
                    if(tops[j] != i && bottoms[j] != i) check = true;
                    if(tops[j] != i) topRotate++;
                    if(bottoms[j] != i) bottomRotate++;
                }
    
                if(!check) return min(topRotate, bottomRotate);
            }
            return -1;
        }
    };