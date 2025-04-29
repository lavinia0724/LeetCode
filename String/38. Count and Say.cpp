// 2025/04/29
class Solution {
    public:
        string countAndSay(int n) {
            if(n == 1) return "1";
    
            string str = countAndSay(n-1);
    
            int cnt = 1;
            string res = "";
            for(int i = 1; i < str.size(); ++i){
                if(str[i-1] != str[i]){
                    res += to_string(cnt) + str[i-1];
                    cnt = 1;
                }
                else cnt++;
    
                if(i == str.size()-1) res += to_string(cnt) + str[i];
            }
            
            return (str == "1") ? "11" : res;
        }
    };