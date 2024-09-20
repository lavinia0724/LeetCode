// 2024/09/20
class Solution {
public:
    // KMP Algorithm
    string shortestPalindrome(string s) {
        string strConcatRevstr = s + "#" + string(s.rbegin(), s.rend()); // abc -> abc#cba

        vector<int> prefixStr(strConcatRevstr.length(), 0);
        int maxPalindromeLen = 0;

        for(int i = 1; i < strConcatRevstr.size(); ++i){
            while(maxPalindromeLen > 0 && strConcatRevstr[i] != strConcatRevstr[maxPalindromeLen]){
                maxPalindromeLen = prefixStr[maxPalindromeLen - 1];
            }
            if(strConcatRevstr[i] == strConcatRevstr[maxPalindromeLen]) maxPalindromeLen++;

            prefixStr[i] = maxPalindromeLen;
        }

        int PalindromeLen = prefixStr[strConcatRevstr.size() - 1];

        string reverseStr = string(s.rbegin(), s.rend());
        string suffix = reverseStr.substr(0, s.size() - PalindromeLen); // 把 reverseStr 沒有被重複到的那段貼到 s 前面
        return suffix + s;
    }
};

/*
s = "aacecaaa"
prefixStr []: 
a a c e c a a a # a a a c e c a a
0 1 0 0 0 1 2 2 0 1 2 2 3 4 5 6 7

prefixStr = 7
string suffix = reverseStr.substr(0, s.size() - PalindromeLen) = a
suffix + s = a + aacecaaa = aaacecaaa
*/