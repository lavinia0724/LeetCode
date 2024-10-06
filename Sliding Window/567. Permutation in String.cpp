// 2024/10/06
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> s1SW(26, 0), s2SW(26, 0);

        for(int i = 0; i < s1.size(); ++i){
            s1SW[s1[i] - 'a']++;
            s2SW[s2[i] - 'a']++;
        }

        // 目前已計算好前 s1.size() 中 s2 有哪些字母
        // 然後往後 slide window 去比對下一段 s2 中 s1.size() 的區間中是否能剛好有 s1 所有字母
        for(int i = 0; i < s2.size() - s1.size(); ++i){
            if(s1SW == s2SW) return true;

            s2SW[s2[i] - 'a']--;
            s2SW[s2[i + s1.size()] - 'a']++;
        }

        return s1SW == s2SW;
    }
};