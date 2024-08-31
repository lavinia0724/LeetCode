// 2024/08/29
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<vector<int>> adjacencyList(stones.size());

        for(int i = 0; i < stones.size(); ++i){
            for(int j = i + 1; j < stones.size(); ++j){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<bool> visited(stones.size(), false);

        for(int i = 0; i < stones.size(); ++i){
            if(!visited[i]){
                cnt++;
                dfs(adjacencyList, visited, i);
            }
        }

        return stones.size() - cnt;
    }

    void dfs(vector<vector<int>>& adjacencyList, vector<bool>& visited, int now){
        visited[now] = true;

        for(int e: adjacencyList[now]){
            if(!visited[e]){
                dfs(adjacencyList, visited, e);
            }
        }
    }
};