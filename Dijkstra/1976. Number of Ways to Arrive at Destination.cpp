// 2025/04/03
class Solution {
    public:
        void Dijkstra(int s, int n, vector<int>& pathCnt, vector<long long int>& distance){
            priority_queue<Item> pq;
            pq.push({s, 0});
            distance[s] = 0;
            pathCnt[s] = 1;
    
            while(!pq.empty()){
                Item now = pq.top();
                pq.pop();
    
                if(now.distance > distance[now.u]) continue;
    
                for(Edge e: G[now.u]){
                    if(distance[e.v] > now.distance + e.w){
                        pathCnt[e.v] = pathCnt[now.u]; // 現在所有能去 e.v 的 pathCnt 更新成必須只能來自 now.u 才夠 shortest
                        distance[e.v] = now.distance + e.w;
                        pq.push({e.v, distance[e.v]});
                    }
                    else if(distance[e.v] == now.distance + e.w){
                        pathCnt[e.v] = (pathCnt[e.v] + pathCnt[now.u]) % mod; // weight 相同 pathCnt 還是可以更新
                    }
                }
            }
        }
    
        int countPaths(int n, vector<vector<int>>& roads) {
            vector<long long int> distance(n, LLONG_MAX);
            for(int i = 0; i < roads.size(); ++i){
                // 無向圖
                G[roads[i][0]].push_back({roads[i][1], roads[i][2]});
                G[roads[i][1]].push_back({roads[i][0], roads[i][2]});
            }
    
            vector<int> pathCnt(n, 0); // 這題要算每個點有多少種路徑可以抵達
    
            Dijkstra(0, n, pathCnt, distance);
    
            return pathCnt[n-1];
        }
    
    private:
        struct Edge{
            int v, w;
        };
        struct Item{
            long long int u, distance;
            bool operator < (const Item &other) const{
                return distance > other.distance; // 由小到大排序
            }
        };
        vector<Edge> G[200];
    
        int mod = 1e9+7;
    };