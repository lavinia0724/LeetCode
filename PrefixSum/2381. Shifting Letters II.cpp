// 2025/01/05
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> strShiftCalculator(s.size(), 0);
        
        for(int i = 0; i < shifts.size(); ++i){
            if(shifts[i][2] == 1){ // backward 
                strShiftCalculator[shifts[i][0]]++; // 從他個頭開始大家都要 shift 1
                if(shifts[i][1] + 1 < s.size()) strShiftCalculator[shifts[i][1] + 1]--; // 讓他的尾巴的下一個 -1 代表到這裡停下不要再 sfhit
            }
            else{ // forward
                strShiftCalculator[shifts[i][0]]--; // 同理，但反過來
                if(shifts[i][1] + 1 < s.size()) strShiftCalculator[shifts[i][1] + 1]++; 
            }
        }

        string ans = "";
        int shiftNumber = 0;
        for(int i = 0; i < s.size(); ++i){
            shiftNumber = (shiftNumber + strShiftCalculator[i]) % 26;

            if(shiftNumber < 0) shiftNumber += 26; // 小於 0 了就加 26

            ans += 'a' + ((s[i] - 'a' + shiftNumber) % 26);
        }
        

        return ans;
    }
};