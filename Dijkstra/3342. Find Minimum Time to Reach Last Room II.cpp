// 2025/05/09
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
            vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
            
            int step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
            minheap.push({0, 0, 0, 0}); // start time = 0，從 (0, 0) 開始，alternate time = 0
            moveTime[0][0] = 0;
    
            while(!minheap.empty()){
                auto now = minheap.top();
                minheap.pop();
    
                int nowTime = now[0];
                int nowRow = now[1];
                int nowCol = now[2];
                int moveTimeAlternate = now[3];

    
                if(nowTime > distance[nowRow][nowCol]) continue; // 現在的時間還不能去這格
                if(nowRow == n-1 && nowCol == m-1) return nowTime;
    
                // distance[nowRow][nowCol] = nowTime;
    
                for(int i = 0; i < 4; ++i){
                    int nextRow = nowRow + step[i][0];
                    int nextCol = nowCol + step[i][1];
    
                    if(nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= m) continue;

                    int waitTime = max(moveTime[nextRow][nextCol] - nowTime, 0); // 這格可以進去的時間 - 目前時間 = 等待進入這格的時間
                    int moveCost = (moveTimeAlternate % 2 == 0 ? 1 : 2);
                    int nextTime = nowTime + waitTime + moveCost;

                    // 變成每個 nextTime 只要 < 就更新一次 distance[nextRow][nextCol]，不用考慮 visited
                    if(nextTime < distance[nextRow][nextCol]){ 
                        distance[nextRow][nextCol] = nextTime;
                        minheap.push({nextTime, nextRow, nextCol, moveTimeAlternate + 1}); 
                        // moveTimeAlternate + 1，因為前面 moveCost 是看 %2 餘數來計算
                    }



                }
            }
            return -1;
    }
};