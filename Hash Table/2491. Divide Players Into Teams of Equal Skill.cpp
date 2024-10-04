// 2024/10/04
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sumNums = accumulate(skill.begin(), skill.end(), 0LL);
        int groups = skill.size() / 2;

        if(sumNums % groups != 0) return -1;

        multimap<int, int> mp;
        for(int i = 0; i < skill.size(); ++i) mp.insert({skill[i], 1});

        long long target = sumNums / groups;
        long long  ans = 0;
        // rbegin: 因為這樣我 21 行的 find 才能在相同 element 時先刪掉由前往後找到的另一個相同 element
        for(auto it = mp.rbegin(); it != mp.rend(); it++){
            long long need = target - it->first;

            auto findNeed = mp.find(need);
            if(findNeed != mp.end()) {
                ans += it->first * findNeed->first;
                mp.erase(findNeed);
            }
            else return -1;
        }

        return ans;
    }
};