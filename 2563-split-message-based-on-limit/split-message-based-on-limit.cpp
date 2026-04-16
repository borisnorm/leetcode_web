
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
