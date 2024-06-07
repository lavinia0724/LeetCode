// 2024/06/07
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int ptr = 0;
        unordered_set<string> dictset(dictionary.begin(), dictionary.end());

        string ans = "";
        while(ptr < sentence.size()){
            // find_first_of("切割字元", 查找起始位置); 找到要切割的第一個字元後回傳位址
            int position = sentence.find_first_of(" ", ptr);
            // substr(位置, 長度) 找子字串
            string substr = sentence.substr(ptr, position-ptr);

            ptr = position+1;

            bool flag = false;
            for(int i = 0; i < substr.size(); ++i){
                if(dictset.contains(substr.substr(0, i))) {
                    ans += substr.substr(0, i);
                    flag = true;
                    break;
                }
            }
            if(!flag) ans += substr;
            
            if(position < 0) break;
            else ans += " ";
        }

        return ans;
    }
};