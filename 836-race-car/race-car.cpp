class Solution {
public:
int racecar(int target)
{
    // BFS: 状态 = (pos, spd)，求最少步数
    queue<pair<int,int>> q;
    unordered_set<string> vis;

    q.push({0, 1});           // 初始位置0，速度1
    vis.insert("0,1");
    int steps = 0;

    while (!q.empty())
    {
        int sz = q.size();    // 当前层的节点数

        for (int i = 0; i < sz; i++)
        {
            auto [pos, spd] = q.front();
            q.pop();

            // 到达目标，返回步数
            if (pos == target) return steps;

            // ---- 指令 A: 加速 ----
            int npos = pos + spd;
            int nspd = spd * 2;
            // 剪枝：位置不超出 [-target, 2*target]，速度绝对值不超过 2*target
            string key = to_string(npos) + "," + to_string(nspd);
            if (abs(npos) <= 2 * target && abs(nspd) <= 2 * target && !vis.count(key))
            {
                vis.insert(key);
                q.push({npos, nspd});
            }

            // ---- 指令 R: 反向 ----
            npos = pos;                        // 位置不变
            nspd = (spd > 0) ? -1 : 1;        // 速度反向重置为±1
            key = to_string(npos) + "," + to_string(nspd);
            if (!vis.count(key))
            {
                vis.insert(key);
                q.push({npos, nspd});
            }
        }

        steps++;  // 这一层全处理完，步数+1
    }

    return -1;  // 理论上不会到达
}
};