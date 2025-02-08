// 2025/02/08
class NumberContainers {
    public:
        NumberContainers() { }
        
        void change(int index, int number) {
            if(idxToNumber.find(index) != idxToNumber.end()){
                int prevNumber = idxToNumber[index];
                numberToIdx[prevNumber].erase(index);
    
                if(numberToIdx[prevNumber].empty()) numberToIdx.erase(prevNumber);
            }
            idxToNumber[index] = number;
            numberToIdx[number].insert(index);
        }
        
        int find(int number) {
            if(numberToIdx.find(number) != numberToIdx.end()) return *numberToIdx[number].begin(); // 回傳紀錄 number 的第一個 idx 的值 (寫法如此，因為這裡用 set 來儲存)
            return -1;
        }
    
    private:
        unordered_map<int, set<int>> numberToIdx;
        unordered_map<int, int> idxToNumber;
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */