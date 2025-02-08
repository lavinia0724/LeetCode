// 2025/02/08
class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            vector<int> ansDistinctColorCnt(queries.size());
            unordered_map<int, int> ballColor, colorCnt;
            for(int i = 0; i < queries.size(); ++i){
                int ball = queries[i][0], color = queries[i][1];
    
                if(ballColor.find(ball) != ballColor.end()){ // 代表之前已經有對這顆球被query過，現在要來改他顏色
                    int prevColor = ballColor[ball];
                    colorCnt[prevColor]--;
    
                    if(colorCnt[prevColor] == 0) colorCnt.erase(prevColor);
                }
                ballColor[ball] = color;
                colorCnt[color]++;
    
                ansDistinctColorCnt[i] = colorCnt.size();
            }
            return ansDistinctColorCnt;
        }
    };