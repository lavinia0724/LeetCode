/* 2024/04/21 */
bool visited[1000000];

bool dfs(int now, deque<int> G[], int destination){
    if(now == destination) return true;
    for(int i = 0; i < G[now].size(); ++i){
        int v = G[now][i];
        
        if(visited[v]) continue;

        visited[v] = true;
        if(dfs(v, G, destination)) return true;
    }
    return false;
}

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        memset(visited, false, sizeof(visited));
        visited[source] = true;

        // edges = [u, v]
        // G[u] = [v1, v2, v3...]
        deque<int> G[n];
        for(int i = 0; i < edges.size(); ++i){
            // 雙向連通圖
            G[edges[i][0]].emplace_back(edges[i][1]);
            G[edges[i][1]].emplace_back(edges[i][0]);
        }
        
        bool ans = dfs(source, G, destination);

        if(ans) return true;
        else return false;
    }
};

