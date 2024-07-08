// 2024/07/08
class Solution {
public:
    int Josphus(vector<int> person, int k, int index){
        if(person.size() == 1) return person[0];

        index = ((index + k) % person.size());
        person.erase(person.begin() + index);
        return Josphus(person, k, index);
    }

    int findTheWinner(int n, int k) {
        int index = 0;

        vector<int> person;
        for(int i = 1; i <= n; ++i) person.emplace_back(i);

        return Josphus(person, k-1, index);
    }
};