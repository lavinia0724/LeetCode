// 2025/02/24
class Solution {
    public:
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            tree.resize(edges.size() + 1);
            visited.resize(edges.size() + 1, false);
    
            for(int i = 0; i < edges.size(); ++i){
                tree[edges[i][0]].push_back(edges[i][1]);
                tree[edges[i][1]].push_back(edges[i][0]);
            }
    
            BobPath[bob] = 0;
            visited[bob] = true;
            BobPathDFS(bob, 0);
    
            fill(visited.begin(), visited.end(), false);
            AlicePathDFS(0, 0, amount, 0);
    
            return maxIncome;
        }
    
    private:
        vector<vector<int>> tree;
        unordered_map<int, int> BobPath;
        vector<bool> visited;
        int maxIncome = INT_MIN;
    
        bool BobPathDFS(int nowNode, int time){
            if(nowNode == 0) {
                BobPath[nowNode] = time;
                return true;
            }
    
            visited[nowNode] = true;
            for(auto nextNode: tree[nowNode]){
                if(visited[nextNode]) continue;
    
                if(BobPathDFS(nextNode, time + 1)) {
                    BobPath[nowNode] = time;
                    return true;
                }
            }
            visited[nowNode] = false;
            return false;
        }
    
        void AlicePathDFS(int nowNode, int time, vector<int>& amount, int income){
            if(BobPath.find(nowNode) == BobPath.end() || time < BobPath[nowNode]){
                income += amount[nowNode];
            }
            else if(time == BobPath[nowNode]){
                income += amount[nowNode]/2;
            }
    
            bool isLeaf = true;
            visited[nowNode] = true;
            for(auto nextNode: tree[nowNode]){
                if(visited[nextNode]) continue;
                isLeaf = false;
                AlicePathDFS(nextNode, time + 1, amount, income);
            }
            visited[nowNode] = false;
    
            if(isLeaf){
                maxIncome = max(maxIncome, income);
            }
        }
    };