// 2025/03/05
class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            string ans = "";
            for(int i = 0; i < nums.size(); ++i){
                ans += ((nums[i][i] == '0') ? '1' : '0'); // 遍歷每個 nums，取他們的每個的其中一位元的相反值，因為這樣答案必有一位元與各 nums 不同
            }
            return ans;
        }
    };