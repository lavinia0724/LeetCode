// 2026/05/08
class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    bool backtracking(string now, int x, int y, vector<vector<char>>& board, vector<vector<bool>>& visited, string target){
        if(now == target) return true;

        int m = board.size(), n = board[0].size();
        for(int i = 0; i < 4; ++i){
            int nextx = x + dx[i];
            int nexty = y + dy[i];

            if(nextx < 0 || nextx >= m || nexty < 0 || nexty >= n) continue;
            if(visited[nextx][nexty]) continue;
            if(board[nextx][nexty] != target[now.size()]) continue;

            visited[nextx][nexty] = true;

            if(backtracking(now + board[nextx][nexty], nextx, nexty, board, visited, target)) return true;

            visited[nextx][nexty] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m+1, vector<bool>(n+1, false));

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] != word[0]) continue;

                string now = "";
                now += board[i][j];

                visited[i][j] = true;
                if(backtracking(now, i, j, board, visited, word)) return true;
                visited[i][j] = false;
            }
        }
        return false;
    }
};