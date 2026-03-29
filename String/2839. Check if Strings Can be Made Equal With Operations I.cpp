// 2026/03/29
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        map<char, int> s1odd;
        map<char, int> s1even;
        for(int i = 0; i < s1.size(); ++i){
            if(i & 1) s1odd[s1[i]]++;
            else s1even[s1[i]]++;
        }
        for(int i = 0; i < s2.size(); ++i){
            if(i & 1) {
                s1odd[s2[i]]--;
                if(s1odd[s2[i]] == 0) s1odd.erase(s2[i]);
            }
            else {
                s1even[s2[i]]--;
                if(s1even[s2[i]] == 0) s1even.erase(s2[i]);
            }
        }

        return (s1odd.size() == 0 && s1even.size() == 0);
    }
};