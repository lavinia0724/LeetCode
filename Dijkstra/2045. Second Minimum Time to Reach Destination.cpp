// 2024/07/28
class Solution {
public:
    struct Item{
        int u;
        int distance;
        // 取路徑最短
        bool operator < (const Item &other) const{
            return distance > other.distance;
        }
    };
    int Dijkstra(int s, int n, vector<int> G[], int time, int change){
        int MiniDistance[n+5], secondMiniDistance[n+5];
        for(int i = 0; i <= n; ++i){
            MiniDistance[i] = 0x3f3f3f3f;
            secondMiniDistance[i] = 0x3f3f3f3f;
        }
        MiniDistance[s] = 0;
        // secondMiniDistance[s] = 0; 因為第二短有可能要來回兩趟，所以不要初始成 0

        priority_queue<Item> pq;
        pq.push({s, 0});

        while(!pq.empty()){
            // 取路徑最短的點
            Item now = pq.top();
            pq.pop();

            if(now.distance > MiniDistance[now.u] && now.distance > secondMiniDistance[now.u]) continue;

            // 鬆弛 更新
            // 把與 now.u 相連的點都跑一遍
            // 利用 else if 判斷 miniDistance 不更新，且 secondMiniDistance 可更新
            // 本題還要判斷紅燈綠燈，綠燈直接正常更新路徑，紅燈還要多加在該點等待的時間 ((now.distance) / change + 1) * change + time
            // 本題最難算的就是這個紅燈判斷，夭壽
            for(int e: G[now.u]){ // 這次 G 直接不推 Edge，所有 G 內的點就是 e.v
                if(MiniDistance[e] > now.distance + time){
                    if((now.distance / change) % 2 != 0){ // 紅燈
                        MiniDistance[e] = ((now.distance) / change + 1) * change + time;
                    }
                    else MiniDistance[e] = now.distance + time; // 綠燈
                    
                    pq.push({e, MiniDistance[e]});
                }
                else if(secondMiniDistance[e] > now.distance + time && MiniDistance[e] != now.distance + time){ // 特別注意: MiniDistance[e] != now.distance + time
                    if((now.distance / change) % 2 != 0){ // 紅燈
                        secondMiniDistance[e] = ((now.distance) / change + 1) * change + time;
                    }
                    else secondMiniDistance[e] = now.distance + time; // 綠燈

                    pq.push({e, secondMiniDistance[e]});
                }
            }
        }
        return secondMiniDistance[n];
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> G[n+5]; // 這次路徑權重固定都是 time，所以不用特地用 Edge 存
        for(int i = 0; i < edges.size(); ++i){
            // 無向圖
            G[edges[i][0]].push_back(edges[i][1]);
            G[edges[i][1]].push_back(edges[i][0]);
        }
        return Dijkstra(1, n, G, time, change);
    }
};