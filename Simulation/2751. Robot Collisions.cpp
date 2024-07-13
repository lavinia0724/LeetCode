// 2024/07/13
class Solution {
public:
    struct Robots{
        int idx;
        int position;
        int health;
        string direction;
    };
    
    static bool cmp(Robots robotA, Robots robotB){
        return robotA.position < robotB.position;
    }
    static bool cmp2(Robots robotA, Robots robotB){
        return robotA.idx < robotB.idx;
    }

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        // n == 1 是特殊情況，可以直接判斷後就回傳
        if(n == 1) {
            vector<int> ans({healths[0]});
            return ans;
        }

        Robots robot[n];
        for(int i = 0; i < n; ++i){
            robot[i].idx = i;
            robot[i].position = positions[i];
            robot[i].health = healths[i];
            robot[i].direction = directions[i];
        }
        sort(robot, robot + n, cmp);

        vector<Robots> survive;
        vector<int> ans;
        stack<Robots> goRight;
        for(int i = 0; i < n; ++i){
            if(robot[i].direction == "R") goRight.push(robot[i]);
            else{
                while(!goRight.empty() && robot[i].health > goRight.top().health){
                    goRight.pop();
                    robot[i].health--;
                }
                if(!goRight.empty() && robot[i].health == goRight.top().health){
                    goRight.pop();
                    continue;
                }

                if(goRight.empty()) survive.emplace_back(robot[i]);
                else goRight.top().health--;
            } 
        }

        while(!goRight.empty()){
            survive.emplace_back(goRight.top());
            goRight.pop();
        }
        sort(survive.begin(), survive.end(), cmp2);

        for(int i = 0; i < survive.size(); ++i) ans.emplace_back(survive[i].health);
        return ans;
    }
};