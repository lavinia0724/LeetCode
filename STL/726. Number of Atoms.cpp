// 2024/07/14
class Solution {
public:
    string countOfAtoms(string formula) {
        vector<string> v;
        map<string, int> mp;
        for(int i = 0; i < formula.size(); ++i){

            if(islower(formula[i])){ // ex: Mg 的 g
                string element = v.back() + formula[i]; // ex: Mg, element = "g", 要再加 "M"
                v.pop_back();
                v.emplace_back(element);
            }
            else if(isdigit(formula[i])) {
                string tmp = string(1, formula[i]);
                while(isdigit(formula[i+1])){
                    tmp += formula[i+1];
                    i++;
                }
                
                if(v.back() == ")"){
                    v.pop_back(); // pop_back ")"

                    string element = "";
                    for(int j = v.size()-1; ; --j){
                        if(v[j] == "("){
                            v.erase(v.begin()+j); // erase "("
                            break;
                        }

                        if(isdigit(v[j][0])){
                            int digit = stoi(v[j]); // stoi: string to int
                            v[j] = to_string(stoi(tmp) * digit); 
                        }
                        else if(j == v.size()-1 || (!isdigit(v[j][0]) && !isdigit(v[j+1][0]))){ // now and next are not digit, ex: OH
                            v.insert(v.begin()+j+1, tmp); 
                        }
                    }
                }
                else v.emplace_back(tmp);
            }
            else if((!isdigit(formula[i]) && !v.empty() && v.back() == ")") || (i == formula.size()-1 && formula[i] == ')')){
                if(formula[i] != ')') {
                    v.pop_back(); // pop_back ")"
                    v.emplace_back(string(1, formula[i])); // ex: "Mg(H2O)N", pop ")", emplace back "N"
                }
                for(int j = v.size()-1; ; --j){
                    if(v[j] == "("){
                        v.erase(v.begin()+j); // erase "("
                        break;
                    }
                }
            }
            else v.emplace_back(string(1, formula[i])); // ex: S

            // for(auto test: v) cout << test << " "; // 我故意留著這行註解... debug 很久... 要參考可以反註解來看...
            // cout << endl;
        }

        while(!v.empty()){
            if(isdigit(v.back()[0])){
                int digit = stoi(v.back());
                v.pop_back();
                if(v.empty()) break;
                mp[v.back()] += digit;
                v.pop_back();
            }
            else {
                mp[v.back()]++;
                v.pop_back();
            }
        }

        string ans = "";
        for(const auto& s: mp) ans = ans + s.first + (s.second == 1 ? "" : to_string(s.second));
        return ans;
    }
};