// 2025/03/21
class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            unordered_map<string, int> mpsupplies;
            for(auto item: supplies) mpsupplies[item]++;
    
            unordered_map<string, int> mprecipies;
            for(int i = 0; i < recipes.size(); ++i) mprecipies[recipes[i]] = i;
    
            vector<int> inDegree(recipes.size(), 0); // 用來計算 Topological Sorting 的 degree
            unordered_map<string, vector<string>> dependencyGraph; 
            for(int i = 0; i < recipes.size(); ++i){
                for(int j = 0; j < ingredients[i].size(); ++j){
                    if(mpsupplies[ingredients[i][j]] <= 0){ // 如果會用到其他 recipes 當 ingredients
                        dependencyGraph[ingredients[i][j]].push_back(recipes[i]); // 創建一條 edge: 該 recipe ingredient -> 這個 recipe 
                        inDegree[i]++; // 代表這個 recipe 前面還有別的點
                    } 
                }
            }
    
            // Start with recipes that only need supplies
            queue<int> q;
            for(int i = 0; i < recipes.size(); ++i){
                if(inDegree[i] == 0) q.push(i);
            }
    
            // Topological Sorting
            vector<string> ans;
            while(!q.empty()){
                int idx = q.front();
                q.pop();
                ans.emplace_back(recipes[idx]);
    
                if(!dependencyGraph.count(recipes[idx])) continue; // 代表這個 recipe 沒有和其他人有關係
    
                for(auto dependentRecipe: dependencyGraph[recipes[idx]]){ // 做完這個 recipe 可以做哪些其他 recipe
                    if(--inDegree[mprecipies[dependentRecipe]] == 0){ // 代表這個 dependentRecipe 只需要現在這個 recipe 做完就可以做了，沒有缺其他原料
                        q.push(mprecipies[dependentRecipe]);
                    }
                }
            }
            return ans;
        }
    };