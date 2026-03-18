
/*
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target == 0)
          return false;
        
        if (target > x + y)
          return false;

        return target % gcd(x, y) == 0;
    }

    //辗转相除法
    int gcd2(int a, int b)
    {
      while (b != 0)              // b 不为 0 就继续
      {
        int tmp = a % b;        // 求余数
        a = b;                  // a 换成 b
        b = tmp;                // b 换成余数
      }
      return a;                   // b=0 时 a 就是答案
   }
};
*/

class Solution
{
public:
    bool canMeasureWater(int j1, int j2, int target)
    {

        int x = j1;
        int y = j2;
        // 特判
        if (target == 0) return true;
        if (target > j1 + j2) return false;

        // BFS 初始化
        queue<pair<int,int>> q;
        set<pair<int,int>> vis;

        q.push({0, 0});
        vis.insert({0, 0});

        while (!q.empty())
        {
            auto [x, y] = q.front();   // 当前状态
            q.pop();

            // 找到答案
            if (x + y == target) return true;

            // 6 种操作，生成下一个状态
            std::vector<std::pair<int,int>> nexts =
            {
                {j1, y},                                        // 装满壶1
                {x, j2},                                        // 装满壶2
                {0, y},                                         // 倒空壶1
                {x, 0},                                         // 倒空壶2
                {x - min(x, j2-y), y + min(x, j2-y)}, // 壶1倒入壶2
                {x + min(y, j1-x), y - min(y, j1-x)}  // 壶2倒入壶1
            };

            for (auto& [nx, ny] : nexts)
            {
                if (vis.count({nx, ny})) continue;  // 已访问跳过
                vis.insert({nx, ny});
                q.push({nx, ny});
            }
        }

        return false;   // 所有状态遍历完，找不到
    }
};