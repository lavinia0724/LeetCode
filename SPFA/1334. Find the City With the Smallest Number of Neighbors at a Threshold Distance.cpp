// 2024/07/26
class Solution {
public:
    struct Edge{
        int v;
        int weight;
    };
    void SPFA(int n, int s, deque<Edge> G[], int &citiesReachable, int distanceThreshold){
        int cnt[n], distance[n];
        bool inqueue[n];
        queue<int> q;

        memset(cnt, 0, sizeof(cnt));
        memset(distance, 0x3f3f3f3f, sizeof(distance));
        memset(inqueue, false, sizeof(inqueue));

        q.push(s);
        distance[s] = 0;
        inqueue[s] = true;
        cnt[s] = 1;

        while(!q.empty()){
            int now = q.front();
            q.pop();
            inqueue[now] = false;

            for(auto &e: G[now]){
                if(distance[e.v] > distance[now] + e.weight){
                    distance[e.v] = distance[now] + e.weight;
                    if(!inqueue[e.v]){
                        cnt[e.v]++;
                        // if(cnt[e.v] > m) return; // 原本的 SPFA 要判斷負環
                        inqueue[e.v] = true;
                        q.push(e.v);
                    }
                }
            }
        }

        for(int i = 0; i < n; ++i){
            if(i == s) continue;
            if(distance[i] <= distanceThreshold) citiesReachable++;
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        deque<Edge> G[n];
        for(int i = 0; i < edges.size(); ++i){
            // 雙向圖
            G[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            G[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        int citiesReachable[n];
        memset(citiesReachable, 0, sizeof(citiesReachable));

        for(int i = 0; i < n; ++i) SPFA(n, i, G, citiesReachable[i], distanceThreshold);

        int maxiCities = 0x3f3f3f3f, maxiIdx = 0;
        for(int i = 0; i < n; ++i){
            if(citiesReachable[i] <= maxiCities){
                maxiCities = citiesReachable[i];
                maxiIdx = i; // 因為是 increasing order 去更新的，必是記錄到 greatest number
            }
        }
        return maxiIdx;
    }
};