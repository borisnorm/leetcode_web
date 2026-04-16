class Solution
{
public:
    // 计算位数：1~9→1, 10~99→2, ...
    int digs(int n)
    {
        if (n <= 9)    return 1;
        if (n <= 99)   return 2;
        if (n <= 999)  return 3;
        if (n <= 9999) return 4;
        return 5;
    }

    // suffix "<i/k>" 长度 = 1 + digs(i) + 1 + digs(k) + 1 = digs(i) + digs(k) + 3
    int suffixLen(int i, int k)
    {
        return digs(i) + digs(k) + 3;
    }

    vector<string> splitMessage(const string& msg, int limit)
    {
        int n = msg.size();

        // ---- 第一阶段：找最小可行 k ----
        // maxK 是当前枚举的 k 上界（9, 99, 999...）
        // 当 a > maxK 时，说明当前位数不够，升一个量级
        int maxK  = 9;
        int pos   = 0; // 模拟消耗 message 的位置
        int a     = 1; // 当前段编号

        while (pos < n)
        {
            // 当前位数已经不够用，升一个量级
            if (a > maxK)
            {
                maxK = maxK * 10 + 9; // 9 → 99 → 999 → ...

                // 剪枝：suffix "<1/maxK>" 已经超过 limit，无解
                if (suffixLen(1, maxK) >= limit)
                    return {};

                // 重新从头模拟
                pos = 0;
                a   = 1;
                continue;
            }

            int avail = limit - suffixLen(a, maxK); // 这段能装多少字符
            if (avail <= 0) return {};               // 无解

            pos += avail;
            a++;
        }

        int k = a - 1; // 最小可行 k

        // ---- 第二阶段：按 k 切割 message ----
        vector<string> res;
        string ks = to_string(k);
        pos = 0;

        for (int i = 1; i <= k; i++)
        {
            int avail = limit - suffixLen(i, k);
            int take  = min(avail, n - pos);         // 最后一段可能不足 avail
            res.push_back(msg.substr(pos, take) + "<" + to_string(i) + "/" + ks + ">");
            pos += take;
        }

        return res;
    }
};



/*
class Solution
{
public:
    // 计算位数
    int digits(int x)
    {
        return (int)to_string(x).size();
    }

    // 优化版 check：按位数分组
    bool canSplit(const string& message, int limit, int b)
    {
        int n = message.size();

        int len_b = digits(b);  // b 的位数

        long long totalCap = 0; // 总容量

        int start = 1;

        // 按位数分组
        for (int d = 1; d <= 5; d++)  // 最多 5 位（n <= 1e4）
        {
            int l = start;
            int r = min(b, start * 10 - 1);

            if (l > r)
                break;

            int count = r - l + 1;

            // suffix 长度
            int suffixLen = d + len_b + 3;

            int cap = limit - suffixLen;

            // 如果这一整组都放不下
            if (cap <= 0)
                return false;

            totalCap += (long long)count * cap;

            start *= 10;
        }

        return totalCap >= n;
    }

    // 构造答案（和之前一样）
    vector<string> build(const string& message, int limit, int b)
    {
        vector<string> ans;

        int n = message.size();
        int idx = 0;

        int len_b = digits(b);

        for (int i = 1; i <= b; i++)
        {
            int len_i = digits(i);

            string suffix = "<" + to_string(i) + "/" + to_string(b) + ">";

            int cap = limit - (len_i + len_b + 3);

            int take = min(cap, n - idx);

            ans.push_back(message.substr(idx, take) + suffix);

            idx += take;
        }

        return ans;
    }

    vector<string> splitMessage(string message, int limit)
    {
        int n = message.size();

        for (int b = 1; b <= n; b++)
        {
            if (canSplit(message, limit, b))
            {
                return build(message, limit, b);
            }
        }

        return {};
    }
};

*/