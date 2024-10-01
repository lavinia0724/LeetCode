// 2024/10/01
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int, int> mp;

        int pairNum = 0;
        for(int i = 0; i < arr.size(); ++i){
            int tmpMod = ((arr[i] % k) + k) % k;
            int pairMod = ((k - tmpMod) == k) ? 0 : (k - tmpMod);
            if(mp[pairMod] > 0){
                mp[pairMod]--;
                pairNum++;
            }
            else mp[tmpMod]++;
        }   

        if(pairNum == arr.size()/2) return true;
        else return false;
    }
};