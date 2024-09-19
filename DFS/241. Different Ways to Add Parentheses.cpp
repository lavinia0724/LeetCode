// 2024/09/19
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for(int i = 0; i < expression.size(); ++i){
            char oper = expression[i];
            if(oper == '+' || oper == '-' || oper == '*'){
                vector<int> substr1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> substr2 = diffWaysToCompute(expression.substr(i + 1));

                for(int a: substr1){
                    for(int b: substr2){
                        if(oper == '+') res.emplace_back(a + b);
                        else if(oper == '-') res.emplace_back(a - b);
                        else if(oper == '*') res.emplace_back(a * b);
                    }
                }
            }
        }

        if(res.empty()) res.emplace_back(stoi(expression)); // 只有可能都是運算子 才會 res 沒東西
        return res;
    }
};