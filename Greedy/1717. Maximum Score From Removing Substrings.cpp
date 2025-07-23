// 2024/07/12
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        int aCount = 0, bCount = 0;
        if(x > y){
            for(int i = 0; i < s.size(); ++i){
                if(s[i] == 'a') aCount++;
                else if(s[i] == 'b'){
                    if(aCount != 0){
                        ans += x;
                        aCount--;
                    }
                    else bCount++;
                }
                else{
                    ans += y * min(aCount, bCount);
                    aCount = 0;
                    bCount = 0;
                }
            }
            ans += y * min(aCount, bCount);
        }
        else{
            for(int i = 0; i < s.size(); ++i){
                if(s[i] == 'b') bCount++;
                else if(s[i] == 'a'){
                    if(bCount != 0){
                        ans += y;
                        bCount--;
                    }
                    else aCount++;
                }
                else{
                    ans += x * min(aCount, bCount);
                    aCount = 0;
                    bCount = 0;
                }
            }
            ans += x * min(aCount, bCount);
        }
        return ans;
    }
};

// ==========================================================================

// 2025/07/23
class Solution {
public:
    int counter(string s, int x, int y, char a, char b){
        stack<char> stk;
        int ans = 0;
        for(auto character: s){
            if(!stk.empty() && stk.top() == b && character == a){
                stk.pop();
                ans += y;
            }
            else stk.push(character);
        }
        string revstr = "";
        while(!stk.empty()){
            revstr += stk.top();
            stk.pop();
        }
        reverse(revstr.begin(), revstr.end());
        for(auto character: revstr){
            if(!stk.empty() && stk.top() == a && character == b){
                stk.pop();
                ans += x;
            }
            else stk.push(character);
        }
        return ans;
    }

    int maximumGain(string s, int x, int y) {
        if(y >= x) return counter(s, x, y, 'a', 'b');
        else return counter(s, y, x, 'b', 'a'); // 倒過來
    }
};