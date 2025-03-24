// 2025/03/24
class Solution {
    public:
        int find(int x) {
            return ((parent[x] < 0) ? x : parent[x] = find(parent[x]));
        }
        int unite(int a, int b){
            int x = find(a);
            int y = find(b);
            if(x != y) {
                parent[x] += parent[y];
                parent[y] = x;
            }
            return x;
        }
    
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            memset(parent, -1, sizeof(parent));
    
            unordered_map<int, int> edgeCnt;
            for(int i = 0; i < edges.size(); ++i){
                int u = edges[i][0], v = edges[i][1];
                int parent = unite(u, v);
                edgeCnt[parent]++; // 計算這個 parent 目前他的這張圖上有多少邊，可能會這個 parent 不是最後的 parent，要確認
            }
    
            // 確認: 把邊集中加到最後的 parent 身上
            for(int i = 0; i < n; ++i){
                if(parent[i] >= 0){
                    edgeCnt[parent[i]] += edgeCnt[i];
                    edgeCnt[i] = 0;
                }
            }
    
            int distinctGraph = 0;
            for(int i = 0; i < n; ++i){
                int absparent = abs(parent[i]);
                // 確定每個點都有邊: 透過 parent 的值可以知道這張圖上有多少點，edgeCnt 可以知道這張圖上最後有多少邊
                // 如果每兩兩點都要有邊，要有 C parent 點數量 取 2，是否等於 edgeCnt
                if(parent[i] < 0 && edgeCnt[i] == absparent * (absparent - 1)/2) distinctGraph++;
                else if (parent[i] == -1) distinctGraph++;
            }
            return distinctGraph;
        }
    private:
        int parent[50+5];
    };