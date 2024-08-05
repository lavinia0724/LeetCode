// 2024/08/05
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> unmap;
        for(int i = 0; i < arr.size(); ++i){
            unmap[arr[i]] += 1;
        }
        
        int idx = arr.size();
        for(int i = 0; i < arr.size(); ++i){
            if(unmap[arr[i]] == 1) k--;
            if(k == 0) return arr[i];
        }
        return "";
    }
};