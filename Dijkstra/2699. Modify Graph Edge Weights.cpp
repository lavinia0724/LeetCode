// 2024/08/30
class Solution {
public:
    struct Edge{
        int v;
        int weight; 
    };
    struct Item{
        int u;
        long long distance;

        // 取路徑最短
        bool operator < (const Item &other) const{
            return distance > other.distance;
        }
    };
    long long Dijkstra(vector<vector<int>>& edges, int n, int source, int destination){
        vector<Edge> G[n];
        long long distance[n];
        memset(distance, 2e9+5, sizeof(distance)); // 設成比 2e9 還大的數值才好 Dijkstra 更新
        bool visited[n];
        memset(visited, false, sizeof(visited));

        distance[source] = 0;
        for(int i = 0; i < edges.size(); ++i){
            if(edges[i][2] == -1) continue; // 讓邊是 -1 的被覆蓋成 2e9
            // 無向圖
            G[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            G[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        priority_queue<Item> pq;
        pq.push({source, 0});

        while(!pq.empty()){
            // 取路徑最短的點
            Item now = pq.top();
            pq.pop();

            if(now.u == destination) break; // 已經找到 source 到 destination 的最短路了，後面不用找了
            if(now.distance > distance[now.u] || visited[now.u]) continue;
            visited[now.u] = true;

            // 鬆弛 更新
            // 把與 now.u 相連的點都跑一遍
            for(Edge e: G[now.u]){
                if(distance[e.v] > now.distance + e.weight){
                    distance[e.v] = now.distance + e.weight;
                    pq.push({e.v, distance[e.v]});
                }
            }
        }
        return distance[destination];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        // 假設將 -1 都改成 2e9，看其最短路徑是否符合 target (也就是希望 -1 的邊都不在最短路徑邊中)
        long long originalDistance = Dijkstra(edges, n, source, destination);

        // 如果 -1 是最大值還讓 distance < target，這個沒救了，直接回傳空 vector
        if(originalDistance < target) return {};

        // 如果這個假設成立了，就真的讓 edges 裡所有 -1 邊都覆蓋成 2e9
        if(originalDistance == target) {
            for(int i = 0; i < edges.size(); ++i) 
                if(edges[i][2] == -1) edges[i][2] = 2e9; // 真的讓 -1 都被覆蓋成 2e9
            return edges;
        }
        // 看來必須用到 -1 調整邊，來看看要怎麼調整
        bool flag = false;
        for(int i = 0; i < edges.size(); ++i){
            if(edges[i][2] != -1) continue; // 不是 -1 的邊不動他
            if(flag) {
                edges[i][2] = 2e9;
                continue;
            }
            edges[i][2] = 1;
            long long newDistance = Dijkstra(edges, n, source, destination);

            if(newDistance <= target){
                // 如果讓這條 -1 變成 1 能讓新的最短路 <= target，等於就是讓這條剛好變 1，小於就是讓它再加上 target - newDistance 的長度，就會剛好等於 target 了
                edges[i][2] += target - newDistance;
                flag = true; // 後面所有的 -1 邊都讓他變成之前假設的 2e9
            }
        }

        if(!flag) return {}; // 代表有調整不了的情況，也是回傳空 vector
        else return edges;
    }
};