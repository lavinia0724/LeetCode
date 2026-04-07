// 2026/04/07
class Robot {
public:
    int w, h;
    int x = 0, y = 0;
    int direction = 0; // 0:E, 1:N, 2:W, 3:S
    int perimeter;

    Robot(int width, int height) {
        w = width;
        h = height;
        perimeter = 2 * (w + h) - 4;
    }
    
    void step(int num) {
        num %= perimeter;

        // 特殊情況：走完整一圈
        if (num == 0) {
            if (x == 0 && y == 0) direction = 3; // South
            return;
        }

        while (num > 0) {
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            // 撞牆 → 轉向
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                direction = (direction + 1) % 4;
                continue;
            }

            // 可以走
            x = nx;
            y = ny;
            num--;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return directions[direction];
    }

private:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    vector<string> directions = {"East", "North", "West", "South"};
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */