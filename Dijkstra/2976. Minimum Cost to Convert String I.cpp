// 2024/07/27
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
    void Dijkstra(int s, vector<Edge> G[], long long distance[]){
        for(int i = 0; i < 26; ++i){
            distance[i] = 0x3f3f3f3f;
        }
        distance[s] = 0;

        priority_queue<Item> pq;
        pq.push({s, 0});

        while(!pq.empty()){
            // 取路徑最短的點
            Item now = pq.top();
            pq.pop();

            if(now.distance > distance[now.u]) continue;

            // 鬆弛 更新
            // 把與 now.u 相連的點都跑一遍
            for(Edge e: G[now.u]){
                if(distance[e.v] > now.distance + e.weight){
                    distance[e.v] = now.distance + e.weight;
                    pq.push({e.v, distance[e.v]});
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {        
        vector<Edge> G[26]; // 存最多 26 個字母的關聯
        for(int i = 0; i < original.size(); ++i){
            // 有向圖
            // 把 char 都對應換成 digit 儲存, ex: a 轉換成 0 當 idx
            G[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }
        
        long long distance[26][26];
        memset(distance, -1, sizeof(distance));
        for(int i = 0; i < 26; ++i) distance[i][i] = 0; // 自己到自己必為 0

        for(int i = 0; i < 26; ++i){
            if(G[i].empty()) continue; // 可能會有沒出現過的字母
            Dijkstra(i, G, distance[i]);
        }

        // 根據本題，把 source 字串中的每個字元，尋找其變成 target 字元的最少 cost
        long long ans = 0;
        for(int i = 0; i < source.size(); ++i){
            if(distance[source[i] - 'a'][target[i] - 'a'] == -1 || distance[source[i] - 'a'][target[i] - 'a'] == 0x3f3f3f3f){
                cout << source[i] << " " << target[i] << endl;
                ans = -1;
                break;
            }
            ans += distance[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};