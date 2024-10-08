// 2024/10/08
class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        int swapCnt = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '[') stk.push(s[i]);
            else{
                if(!stk.empty() && stk.top() == '[') stk.pop();
                else swapCnt++;
            }
        }
        return (swapCnt + 1) / 2;
    }
};