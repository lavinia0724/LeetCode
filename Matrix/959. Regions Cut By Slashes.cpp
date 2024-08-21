// 2024/08/10
class Solution {
public:
    // 並查集 Disjoint Set
    int find(vector<int>& parent, int x){
        return parent[x] == -1 ? x : parent[x] = find(parent, parent[x]); 
    }
    int unionSet(vector<int>& parent, int a, int b){
        int x = find(parent, a);
        int y = find(parent, b);

        if(x == y) return 1; // 如果祖先相同，代表有圍出一個區域了

        parent[y] = x; // 否則更新祖先
        return 0; // 尚未圍出一個區域
    }

    int regionsBySlashes(vector<string>& grid) {
        vector<int> parent((grid.size() + 1) * (grid.size() + 1), -1); // 祖先初始化全 -1 (自己)
        for(int i = 0; i < grid.size() + 1; ++i){
            for(int j = 0; j < grid.size() + 1; ++j){
                if(i == 0 || j == 0 || i == grid.size() || j == grid.size()){
                    parent[i * (grid.size() + 1) + j] = 0; // 最外圍邊框的祖先更新成 0，也就是把圖形最外圍都畫邊界
                }
            }
        }

        parent[0] = -1; // 最左上角的 parent 設成 -1
        int regionCnt = 1; // 從只有一個區域開始，一定至少會有一個被外圍邊框框起的區域

        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid.size(); ++j){
                if(grid[i][j] == '/'){
                    int topRight = i * (grid.size() + 1) + (j + 1);
                    int bottomLeft = (i + 1) * (grid.size() + 1) + j;
                    regionCnt += unionSet(parent, topRight, bottomLeft);
                }
                else if(grid[i][j] == '\\'){
                    int topLeft = i * (grid.size() + 1) + j;
                    int bottomRight = (i + 1) * (grid.size() + 1) + (j + 1);
                    regionCnt += unionSet(parent, topLeft, bottomRight);
                }
            }
        }
        return regionCnt;
    }
};