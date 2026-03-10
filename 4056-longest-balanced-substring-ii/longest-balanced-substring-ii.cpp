class Solution
{
public:
    int longestBalanced(string s)
    {
        int ans = 0;                                                    // 记录全局最大答案

        ans = max(ans, calcOneChar(s));                                 // 情况1：只有1种字符
        ans = max(ans, calcTwoChars(s, 'a', 'b'));                      // 情况2：只含 a 和 b
        ans = max(ans, calcTwoChars(s, 'a', 'c'));                      // 情况2：只含 a 和 c
        ans = max(ans, calcTwoChars(s, 'b', 'c'));                      // 情况2：只含 b 和 c
        ans = max(ans, calcThreeChars(s));                              // 情况3：同时含 a、b、c

        return ans;                                                     // 返回最终答案
    }

private:
    int calcOneChar(const string& s)
    {
        int n = static_cast<int>(s.size());                             // 字符串长度
        int best = 0;                                                   // 最长连续段长度
        int i = 0;                                                      // 扫描指针

        while (i < n)                                                   // 线性扫描整个字符串
        {
            int j = i;                                                  // j 用来扩展当前连续段

            while (j < n && s[j] == s[i])                               // 找到和 s[i] 相同的连续区间
            {
                j++;                                                    // 继续向右扩展
            }

            best = max(best, j - i);                                    // 更新最长连续段
            i = j;                                                      // 跳到下一段开始位置
        }

        return best;                                                    // 返回只有1种字符时的最大长度
    }

    int calcTwoChars(const string& s, char x, char y)
    {
        int best = 0;                                                   // 当前这对字符的最大平衡长度
        int diff = 0;                                                   // diff = count(x) - count(y)

        unordered_map<int, int> first;                                  // 记录某个 diff 第一次出现的位置
        first[0] = -1;                                                  // 前缀差值为0时，位置视为 -1

        for (int i = 0; i < static_cast<int>(s.size()); i++)            // 扫描整个字符串
        {
            if (s[i] != x && s[i] != y)                                 // 如果遇到第三种字符
            {
                diff = 0;                                               // 当前段失效，重置 diff
                first.clear();                                          // 清空哈希表，因为不能跨第三种字符
                first[0] = i;                                           // 新段起点前的位置设为 i
                continue;                                               // 继续处理下一个字符
            }

            if (s[i] == x)                                              // 如果当前字符是 x
            {
                diff++;                                                 // x 记作 +1
            }
            else                                                        // 否则当前字符必然是 y
            {
                diff--;                                                 // y 记作 -1
            }

            if (first.count(diff))                                      // 如果这个 diff 以前出现过
            {
                best = max(best, i - first[diff]);                      // 中间这段 x 和 y 个数相等
            }
            else                                                        // 如果这是第一次见到该 diff
            {
                first[diff] = i;                                        // 记录最早位置，方便拿最长长度
            }
        }

        return best;                                                    // 返回这对字符的最大平衡长度
    }

    long long makeKey(int d1, int d2)
    {
        long long base = 200001LL;                                      // 偏移基数，避免负数冲突
        long long k1 = static_cast<long long>(d1) + base;               // 将 d1 转成非负
        long long k2 = static_cast<long long>(d2) + base;               // 将 d2 转成非负
        return (k1 << 32) ^ k2;                                         // 拼成一个 long long key
    }

    int calcThreeChars(const string& s)
    {
        int best = 0;                                                   // 3种字符同时存在时的最大长度
        int cntA = 0;                                                   // 前缀中 a 的个数
        int cntB = 0;                                                   // 前缀中 b 的个数
        int cntC = 0;                                                   // 前缀中 c 的个数

        unordered_map<long long, int> first;                            // 记录状态第一次出现的位置
        first[makeKey(0, 0)] = -1;                                      // 初始状态：三个字符计数都为0

        for (int i = 0; i < static_cast<int>(s.size()); i++)            // 扫描整个字符串
        {
            if (s[i] == 'a')                                            // 如果当前字符是 a
            {
                cntA++;                                                 // a 的前缀计数加1
            }
            else if (s[i] == 'b')                                       // 如果当前字符是 b
            {
                cntB++;                                                 // b 的前缀计数加1
            }
            else                                                        // 否则当前字符只能是 c
            {
                cntC++;                                                 // c 的前缀计数加1
            }

            int d1 = cntA - cntB;                                       // 第一个差值：a - b
            int d2 = cntA - cntC;                                       // 第二个差值：a - c
            long long key = makeKey(d1, d2);                            // 组合成唯一状态 key

            if (first.count(key))                                       // 如果该状态之前出现过
            {
                best = max(best, i - first[key]);                       // 中间这段满足 a=b=c
            }
            else                                                        // 如果这是第一次出现该状态
            {
                first[key] = i;                                         // 记录最早位置
            }
        }

        return best;                                                    // 返回3种字符平衡时的最大长度
    }
};
