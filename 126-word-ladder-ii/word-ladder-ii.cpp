class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> dict;                                      // 字典集合：O(1) 查找
        for (int i = 0; i < (int)wordList.size(); i++)                   // 遍历 wordList
        {
            dict.insert(wordList[i]);                                    // 加入集合
        }

        vector<vector<string>> ans;                                      // 最终答案
        if (!dict.count(endWord))                                        // 如果 endWord 不在字典中
        {
            return ans;                                                  // 不可能到达，返回空
        }

        unordered_map<string, int> dist;                                 // dist[w] = 从 beginWord 到 w 的最短步数
        unordered_map<string, vector<string>> par;                       // par[w] = 所有最短路径下 w 的前驱列表

        queue<string> q;                                                 // BFS 队列
        q.push(beginWord);                                               // 从起点入队
        dist[beginWord] = 0;                                             // 起点距离为 0

        int L = (int)beginWord.size();                                   // 单词长度（题意固定长度）
        int foundEndDist = -1;                                           // 记录首次到达 endWord 的最短距离

        while (!q.empty())                                               // BFS 直到队列空
        {
            int sz = (int)q.size();                                      // 当前层大小
            for (int i = 0; i < sz; i++)                                 // 逐个处理当前层节点
            {
                string cur = q.front();                                  // 取队头
                q.pop();                                                 // 出队

                int curDist = dist[cur];                                 // 当前单词最短距离

                if (foundEndDist != -1 && curDist >= foundEndDist)       // 如果已找到 endWord 且当前层不更短
                {
                    continue;                                            // 不再向外扩展更深层
                }

                string nxt = cur;                                        // 生成邻居用的临时字符串
                for (int p = 0; p < L; p++)                              // 枚举每个位置
                {
                    char old = nxt[p];                                   // 保存原字符
                    for (char c = 'a'; c <= 'z'; c++)                    // 尝试替换为 26 个字母
                    {
                        if (c == old)                                    // 如果没变化
                        {
                            continue;                                    // 跳过
                        }

                        nxt[p] = c;                                      // 替换一位得到候选邻居

                        if (!dict.count(nxt))                             // 如果不在字典中
                        {
                            continue;                                    // 不是合法单词
                        }

                        if (!dist.count(nxt))                             // 如果 nxt 第一次被发现
                        {
                            dist[nxt] = curDist + 1;                     // 记录最短距离
                            par[nxt].push_back(cur);                     // 记录前驱 cur
                            q.push(nxt);                                 // 入队用于后续扩展

                            if (nxt == endWord)                          // 如果到达终点
                            {
                                foundEndDist = dist[nxt];                // 记录最短终点距离（固定最短层）
                            }
                        }
                        else if (dist[nxt] == curDist + 1)               // 如果 nxt 已发现且仍然是最短层到达
                        {
                            par[nxt].push_back(cur);                     // 追加一个最短前驱
                        }
                        else                                             // dist[nxt] < curDist+1 的情况
                        {
                            /* 不做事：说明这是更长的路径，不能加入 parents，否则会混入非最短 */
                        }
                    }
                    nxt[p] = old;                                        // 还原该位置字符
                }
            }

            if (foundEndDist != -1)                                      // 如果这一层里已经找到过 endWord
            {
                break;                                                   // 由于 BFS 分层，继续更深只会更长，直接停止
            }
        }

        if (foundEndDist == -1)                                          // BFS 完都没找到 endWord
        {
            return ans;                                                  // 无解
        }

        vector<string> path;                                             // 回溯路径（从 endWord 往回）
        path.push_back(endWord);                                         // 从终点开始

        dfsBuild(endWord, beginWord, par, path, ans);                    // DFS 枚举所有最短路径

        return ans;                                                      // 返回答案
    }

private:
    void dfsBuild(const string& cur,
                  const string& beginWord,
                  unordered_map<string, vector<string>>& par,
                  vector<string>& path,
                  vector<vector<string>>& ans)
    {
        if (cur == beginWord)                                            // 回溯到起点
        {
            vector<string> one = path;                                   // 复制当前路径（目前是 end -> ... -> begin）
            reverse(one.begin(), one.end());                             // 翻转得到 begin -> ... -> end
            ans.push_back(one);                                          // 加入答案
            return;                                                      // 返回
        }

        if (!par.count(cur))                                             // 如果没有前驱（理论上不该发生，但防御）
        {
            return;                                                      // 无法继续回溯
        }

        vector<string>& ps = par[cur];                                   // 取 cur 的所有最短前驱
        for (int i = 0; i < (int)ps.size(); i++)                         // 遍历每个前驱
        {
            const string& pre = ps[i];                                   // 当前前驱
            path.push_back(pre);                                         // 选择：加入路径
            dfsBuild(pre, beginWord, par, path, ans);                    // 递归回溯
            path.pop_back();                                             // 撤销选择
        }
    }
};