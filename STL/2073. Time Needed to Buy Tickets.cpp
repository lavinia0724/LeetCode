/* 2024/04/09 */
class Solution { 
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int Costseconds = tickets[k] * tickets.size();
        for(int i = 0; i < k; ++i){
            if(tickets[i] < tickets[k]){
                Costseconds -= (tickets[k] - tickets[i]);
            }
        }
        for(int i = k+1; i < tickets.size(); ++i){
            if(tickets[i] < tickets[k]){
                Costseconds -= (tickets[k] - tickets[i]);
            }
            else{
                Costseconds -= 1;    
            }
        }
        return Costseconds;
    }
};