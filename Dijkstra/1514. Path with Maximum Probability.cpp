// 2024/08/27
class Solution {
public:
    struct Edge{
        int v;
        double weight; // 機率
    };
    struct Item{
        int u;
        double distance; // 路徑就是機率

        // 取路徑(機率)最大
        bool operator < (const Item &other) const{
            return distance < other.distance;
        }
    };
    double Dijkstra(int s, int n, vector<Edge> G[], int end_node){
        double distance[n];
        memset(distance, 0.0, sizeof(distance));

        distance[s] = 1;

        priority_queue<Item> pq;
        pq.push({s, 1.0}); // 自己到自己的機率肯定是 1

        while(!pq.empty()){
            // 取路徑最短的點
            Item now = pq.top();
            pq.pop();

            // 鬆弛 更新
            for(Edge e: G[now.u]){
                if(distance[e.v] < now.distance * e.weight){
                    distance[e.v] = now.distance * e.weight;
                    pq.push({e.v, distance[e.v]});
                }
            }
        }

        return distance[end_node];
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<Edge> G[n+5]; 
        for(int i = 0; i < edges.size(); ++i){
            // 無向圖
            G[edges[i][0]].push_back({edges[i][1], succProb[i]});
            G[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        return Dijkstra(start_node, n, G, end_node);
    }
};