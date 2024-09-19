// 2024/09/15
class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> prefixXOR(s.size() + 1, 0);
        // a: 00001, e: 00010, i: 00100, o: 01000, u: 10000
        map<int, int> mp;
        mp[0] = -1;

        int ans = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'a') prefixXOR[i + 1] = prefixXOR[i] ^ 1;
            else if(s[i] == 'e') prefixXOR[i + 1] = prefixXOR[i] ^ 2;
            else if(s[i] == 'i') prefixXOR[i + 1] = prefixXOR[i] ^ 4;
            else if(s[i] == 'o') prefixXOR[i + 1] = prefixXOR[i] ^ 8;
            else if(s[i] == 'u') prefixXOR[i + 1] = prefixXOR[i] ^ 16;
            else prefixXOR[i + 1] = prefixXOR[i];


            if(mp.find(prefixXOR[i + 1]) == mp.end() && prefixXOR[i + 1] != 0) mp[prefixXOR[i + 1]] = i; // 如果還沒存過第一次這個母音出現的位置，存位置
            
            ans = max(ans, i - mp[prefixXOR[i + 1]]); // 如果已存過，就計算現在的位置 - 曾經的位置最遠的距離
        }   
        return ans;
    }
};

/*
l  e  e  t  c  o  d  e  g  r  e  a  t
0  2  2  0  0  8  0  2  0  0  2  1  0  // a: 00001, e: 00010, i: 00100, o: 01000, u: 10000
0  2  0  0  0  8  8  10 10 10 8  9  9  // prefixXOR
*/