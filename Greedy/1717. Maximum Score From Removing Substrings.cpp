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