class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> dict;                                             // 用集合存字典，O(1) 查找
        for (const string& w : wordList)                                         // 遍历输入单词表
        {
            dict.insert(w);                                                     // 插入到集合
        }

        if (dict.find(endWord) == dict.end())                                   // 如果终点不在字典里
        {
            return 0;                                                           // 无法到达
        }

        unordered_map<string, int> dist;                                        // dist[word] = 从 begin 到 word 的最短步数(边数)
        unordered_map<string, vector<string>> parents;                          // parents[v] = 所有最短前驱 u 的集合（可用于126）

        queue<string> q;                                                        // BFS 队列
        q.push(beginWord);                                                      // 起点入队
        dist[beginWord] = 0;                                                    // 起点距离为0（0条边）

        int foundEndDist = -1;                                                  // 记录 endWord 的最短距离（边数），-1表示尚未找到

        while (!q.empty())                                                      // BFS 主循环
        {
            string cur = q.front();                                             // 取队首
            q.pop();                                                            // 弹出队首

            int curDist = dist[cur];                                            // 当前单词的最短距离（边数）

            if (foundEndDist != -1 && curDist >= foundEndDist)                  // 若已找到 end 的最短层，且当前层不更小
            {
                continue;                                                       // 继续弹队列，但不再扩展（更深层不可能更短）
            }

            string nxt = cur;                                                   // 准备生成邻居：先复制一份
            for (int i = 0; i < (int)cur.size(); i++)                           // 枚举替换位置
            {
                char old = nxt[i];                                              // 保存原字符
                for (char c = 'a'; c <= 'z'; c++)                               // 尝试26个字母
                {
                    if (c == old)                                               // 如果没变化
                    {
                        continue;                                               // 跳过
                    }

                    nxt[i] = c;                                                 // 替换成新字符，得到邻居单词

                    if (dict.find(nxt) == dict.end() && nxt != endWord)         // 若不在字典且也不是终点
                    {
                        continue;                                               // 不是合法节点
                    }

                    if (!dist.count(nxt))                                       // 若第一次到达 nxt
                    {
                        dist[nxt] = curDist + 1;                                // 记录最短距离
                        parents[nxt].push_back(cur);                            // 记录最短前驱 cur
                        q.push(nxt);                                            // 入队

                        if (nxt == endWord)                                     // 如果刚到达终点
                        {
                            foundEndDist = dist[nxt];                           // 记录终点最短距离（边数）
                        }
                    }
                    else if (dist[nxt] == curDist + 1)                          // 若又找到一条同样短的到达方式
                    {
                        parents[nxt].push_back(cur);                            // 把 cur 也作为 nxt 的一个最短前驱
                    }
                }
                nxt[i] = old;                                                   // 恢复字符，继续下一个位置
            }
        }

        if (!dist.count(endWord))                                               // BFS 后仍没到达终点
        {
            return 0;                                                           // 不可达
        }

        return dist[endWord] + 1;                                               // 返回“单词数”= 边数+1
    }
};


/*
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int L = beginWord.size();
        bool found = false;

        for (auto &w: wordList)
        {
           if (w == endWord)
           {
              found = true;
              break;
           }
        }

        if (!found)
          return 0;

        bool hasBegin = false;
        for (auto &w: wordList)
        {
            if (w == beginWord)
            {
                hasBegin = true;
                break;
            }
        }

        if (!hasBegin)
          wordList.push_back(beginWord);

        //1. patter-> words
        unordered_map<string, vector<string>> patternMap;
        
        for (const string &word: wordList)
        {

            for (int i = 0; i < L; i++)
            {
                string pattern = word;
                pattern[i] = '*';
                patternMap[pattern].push_back(word);
            }
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty())
        {
            auto [word, step] = q.front();
            q.pop();

            if (word == endWord)
              return step;

            for (int i = 0; i < L; i++)
            {
               string pattern = word;
               pattern[i] = '*';

               auto it = patternMap.find(pattern);
               if (it == patternMap.end())
                 continue;

               for (const string &next: it->second)
               {
                  if (!visited.count(next))
                  {
                     visited.insert(next);
                     q.push({next, step + 1});
                  }
               }

               it->second.clear();
            }
        }

        return 0;
    }
};

*/