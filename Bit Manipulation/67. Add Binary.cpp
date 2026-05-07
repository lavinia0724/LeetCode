// 2026/05/07
class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        
        int i = m-1, j = n-1, carry = 0;
        string ans = "";
        while(i >= 0 || j >= 0 || carry){
            int sum = carry;

            if(i >= 0) sum += a[i] - '0';
            if(j >= 0) sum += b[j] - '0';

            ans += (sum % 2) + '0';
            carry = sum / 2;
            --i;
            --j;
        }
        reverse(ans.begin(), ans.end()); // 因為是反著組的
        return ans;
    }
};