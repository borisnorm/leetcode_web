/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

class Solution
{
public:
    // 计算两个长度为 6 的单词有多少个位置字符完全相同
    int match(const string& a, const string& b)
    {
        int cnt = 0;                                // 记录匹配位置数

        for (int i = 0; i < 6; ++i)                 // 枚举 6 个位置
        {
            if (a[i] == b[i])                       // 如果当前位置字符相同
            {
                cnt++;                              // 匹配数加 1
            }
        }

        return cnt;                                 // 返回总匹配数
    }

    // 主函数：通过调用 master.guess 来找到 secret word
    void findSecretWord(vector<string>& words, Master& master)
    {
        vector<string> cand = words;             // 当前候选集合，初始为全部单词

        for (int step = 0; step < 30 && !cand.empty(); ++step)   // 最多猜 10 次
        {
            int bestIndex = 0;                      // 记录当前最优猜测单词的下标
            int bestWorst = INT_MAX;                // 记录“最坏情况下剩余候选数”的最小值

            // 枚举当前候选集合中的每个单词，尝试把它作为本轮猜测
            for (int i = 0; i < (int)cand.size(); ++i)
            {
                unordered_map<int, int> groups;     // groups[k] = 与 cand[i] 匹配数为 k 的单词个数

                // 统计 cand[i] 与所有候选词的匹配数分布
                for (int j = 0; j < (int)cand.size(); ++j)
                {
                    if (i == j)                     // 自己和自己也可以统计，影响不大
                    {
                        continue;                   // 这里跳过自己，逻辑更清晰
                    }

                    int m = match(cand[i], cand[j]); // 计算匹配位置数
                    ++groups[m];                   // 对应组的人数加 1
                }

                int worst = 0;                     // 假设猜 cand[i] 时，最坏情况下剩余候选数

                // 找出最大的那一组
                for (const auto& p : groups)
                {
                    worst = max(worst, p.second);  // 取所有组中最大的大小
                }

                // 选择 worst 最小的单词，也就是 minimax
                if (worst < bestWorst)
                {
                    bestWorst = worst;             // 更新当前最优的最坏值
                    bestIndex = i;                 // 记录最优单词下标
                }
            }

            string guessWord = cand[bestIndex];    // 取出本轮要猜的单词
            int res = master.guess(guessWord);     // 调用接口，获得匹配位置数

            if (res == 6)                          // 如果 6 个位置都匹配，说明猜中了
            {
                return;                            // 直接结束
            }

            vector<string> nextCand;               // 下一轮保留下来的候选集合

            // 只保留与 guessWord 的匹配数恰好等于 res 的单词
            for (const string& w : cand)
            {
                if (match(guessWord, w) == res)    // 满足返回值约束，才可能是 secret
                {
                    nextCand.push_back(w);         // 放入下一轮候选集合
                }
            }

            cand = nextCand;                       // 更新候选集合
        }
    }
};

/*
//未知错误

class Solution {
public:
    int match(const string& a, const string& b)
    {
        int cnt = 0;
        for (int i = 0; i < 6; i++)
        {
            if (a[i] == b[i])
              cnt++;
        }
        return cnt;
    }
    void findSecretWord(vector<string>& words, Master& master) {
        vector<string> cands = words;

        for (int i = 0; i < 10 && !cands.empty(); i++)
        {
           string best;
           int bestMax = INT_MAX;

           for (auto& word: words)
           {
              vector<int> buckets(7, 0);
              for (auto& check_word: cands)
              {
                //if (check_word == word)
                //   continue;
                buckets[match(word, check_word)]++;
              }
              
              int worst = *max_element(buckets.begin(), buckets.end());
              if (worst < bestMax)
              {
                  bestMax = worst;
                  best = word;
              }
           }

           int m = master.guess(best);
           if (m == 6)
             return;
           
            vector<string> nxt;
            for(auto& cand: cands)
            {
                if (match(best, cand) == m)
                  nxt.push_back(cand);
            }

            cands = nxt;
        }
    }
};

*/