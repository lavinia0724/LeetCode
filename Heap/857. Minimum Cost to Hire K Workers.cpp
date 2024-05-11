/* 2024/05/11 */
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> ratio;

        // ratio 是每個 worker 每點素質需要多少錢
        for(int i = 0; i < quality.size(); ++i){
            ratio.push({(double(wage[i])/double(quality[i])), i});
        }

        // 透過 priority_queue，取出每點素質需要的錢越少的前 k 位 worker
        // qualitySum 是聘用 k 位員工總共有多少素質
        // RatioMax 是因為每個員工都必須獲得 ratio 最大的那位員工的等比例薪水
        priority_queue<pair<double, int>> pickedWorker;
        double maxRate = 0.0, qualitySum = 0;
        for(int i = 0; i < k; ++i){
            double ratioNow = ratio.top().first;
            int now = ratio.top().second;
            ratio.pop();

            pickedWorker.push({quality[now], now});

            qualitySum += quality[now];
            if(ratioNow > maxRate){
                maxRate = ratioNow;
            }
        }

        // 依序把剩下的 worker 跑完，剩下的 worker 聘用的 ratio 一定比較高
        // 但試試看替換掉原 quality 最大的員工(因為因為 quality 越大要付他越多錢)後是否總薪水會越小
        // 也就是雖然 ratio (每點素質要支付的薪水) 變多了，但因為要支付的總 quality 量變小了，所以有可能要支付的總薪水反而減少
        double ans = maxRate * qualitySum;
        while(!ratio.empty()){
            double ratioNow = ratio.top().first;
            int now = ratio.top().second;
            ratio.pop();

            qualitySum = qualitySum - pickedWorker.top().first + quality[now];

            ans = min(ans, ratioNow * qualitySum);

            pickedWorker.pop(); // 原 ratio 最小的員工也是最先推入的員工
            pickedWorker.push({quality[now], now});
            
        }
        return ans;
    }
};