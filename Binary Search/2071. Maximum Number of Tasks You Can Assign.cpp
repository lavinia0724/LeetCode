// 2025/05/01
class Solution {
    public:
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            int left = 0, right = min(tasks.size(), workers.size());
    
            sort(tasks.begin(), tasks.end());
            sort(workers.begin(), workers.end());
    
            while(left < right){
                int mid = (left + right + 1) / 2;
                int usedPills = 0;
                multiset<int> workersFree(workers.end() - mid, workers.end()); // multiset 是 set 但不剔除重複數字版，這裡存 mid ~ end 的 workers
    
                bool canAssign = true;
                for(int i = mid - 1; i >= 0; --i){
                    auto it = prev(workersFree.end()); // 回傳一個指向 workersFree 容器中最後一個實際存在的元素
    
                    if(*it < tasks[i]){ // workersFree 最後一個 work 也無法負荷 tasks[i]
                        it = workersFree.lower_bound(tasks[i] - strength);  // 找 tasks[i] - strength 後最小的 lower bound 的 worker 讓他吃 pill
                        ++usedPills;
                        if(it == workersFree.end() || usedPills > pills){
                            canAssign = false; // 沒有 worker 吃了 pill 可以負荷這個 tasks，不可能完成了 or 需要太多吃 pills 的 worker 才能做完
                            break;
                        }
                    }
                    workersFree.erase(it); // it 的 worker 現在不 free 了
                }
    
                if(!canAssign) right = mid - 1;
                else left = mid;
            }
            return left; // 因為 left 更新成 mid，可以理解是有幾個 worker 完成了 task
        }
    };