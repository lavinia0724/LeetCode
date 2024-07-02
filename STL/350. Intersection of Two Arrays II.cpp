// 2024/07/03
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp1, mp2;
        for(int i = 0; i < nums1.size(); ++i){
            mp1[nums1[i]]++;
        }

        for(int i = 0; i < nums2.size(); ++i){
            mp2[nums2[i]]++;
        }

        vector<int> ans;
        if(mp1.size() <= mp2.size()){
            for(auto iter = mp1.begin(); iter != mp1.end(); ++iter){
                if(mp2.find(iter->first) != mp2.end()){
                    for(int i = 0; i < min(mp1[iter->first], mp2[iter->first]); ++i){
                        ans.emplace_back(iter->first);
                    }
                }
            }
        }
        else{
            for(auto iter = mp2.begin(); iter != mp2.end(); ++iter){
                if(mp1.find(iter->first) != mp1.end()){
                    for(int i = 0; i < min(mp1[iter->first], mp2[iter->first]); ++i){
                        ans.emplace_back(iter->first);
                    }
                }
            }
        }
        return ans;
    }
};