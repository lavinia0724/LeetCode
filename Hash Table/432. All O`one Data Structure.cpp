// 2024/10/01
class AllOne {
public:
    unordered_map<string, int> mp;
    multimap<int, string> freq;

    static bool cmp(pair<string, int>& a, pair<string, int>& b) {
        return a.second < b.second; // 根據值排序
    }

    AllOne() { }
    
    void inc(string key) {
        // 把 freq 中 key 的頻率刪掉，然後更新 +1 後插入
        auto it = freq.find(mp[key]);
        while(it != freq.end() && it->second != key) ++it;
        if(it != freq.end()) freq.erase(it);

        mp[key]++;
        freq.insert({mp[key], key});
    }
    
    void dec(string key) {
        // 把 freq 中 key 的頻率刪掉，然後更新 -1 後插入
        auto it = freq.find(mp[key]);
        while(it != freq.end() && it->second != key) ++it;
        if(it != freq.end()) freq.erase(it);

        if(mp[key] == 1) mp.erase(key);
        else {
            mp[key]--;
            freq.insert({mp[key], key});
        }
    }
    
    string getMaxKey() {
        if(mp.empty()) return "";
        return freq.rbegin()->second;
    }
    
    string getMinKey() {
        if(mp.empty()) return "";
        return freq.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */