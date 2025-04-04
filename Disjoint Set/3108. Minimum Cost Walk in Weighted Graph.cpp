// 2025/04/04
class Solution {
    public:
        int find(int x){
            return ((parent[x] < 0) ? x : parent[x] = find(parent[x]));
        }
        void unite(int a, int b){
            int x = find(a);
            int y = find(b);
            if(x != y){
                parent[x] += parent[y];
                parent[y] = x;
            }
        }
    
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
            parent.resize(n, -1);
    
            for(int i = 0; i < edges.size(); ++i) unite(edges[i][0], edges[i][1]);
    
            int bitCount = 17; // 2^17 = 131,072 > 10^5
            int maxValue = (1 << bitCount) - 1; // 所有位都是1的值
            vector<int> rootparentwithallcost(n, maxValue);
            for(int i = 0; i < edges.size(); ++i){
                int rootparent = find(edges[i][0]); // 因為不一定每個點都有邊，所以要找一定只能從有邊的點來找
                rootparentwithallcost[rootparent] &= edges[i][2]; // 如果要找到整張圖的 minimum cost，因為 and 特性，就是把整張圖所有連接邊都 and 進去，一定最小
            }
    
            vector<int> ans;
            for(int i = 0; i < query.size(); ++i){
                if(find(query[i][0]) != find(query[i][1])) ans.emplace_back(-1); // 這兩點不在同一圖上
                else{
                    int rootparent = find(query[i][0]);
                    ans.emplace_back(rootparentwithallcost[rootparent]);
                }
            }
            return ans;
        }
    
    private:
        vector<int> parent;
    };