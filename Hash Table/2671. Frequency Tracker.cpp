// 2025/04/05
class FrequencyTracker {
    public:
        FrequencyTracker() { }
        
        void add(int number) {
            if(mp.count(number) != 0){
                frequencymp[mp[number]].erase(number); // 移除原本頻率的 number
            }
            mp[number]++;
            frequencymp[mp[number]].insert(number);
        }
        
        void deleteOne(int number) {
            if(mp[number] == 0) return; // 如果本來就沒有 number 直接回傳
            frequencymp[mp[number]].erase(number); // 移除原本頻率的 number
            mp[number]--;
            frequencymp[mp[number]].insert(number);
        }
        
        bool hasFrequency(int frequency) {
            if(frequencymp[frequency].size() > 0) return true;
            return false;
        }
    
    private:
        unordered_map<int, int> mp;
        unordered_map<int, unordered_set<int>> frequencymp;
    };
    
    /**
     * Your FrequencyTracker object will be instantiated and called as such:
     * FrequencyTracker* obj = new FrequencyTracker();
     * obj->add(number);
     * obj->deleteOne(number);
     * bool param_3 = obj->hasFrequency(frequency);
     */