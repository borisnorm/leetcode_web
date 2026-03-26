
class Solution
{
public:
    string nearestPalindromic(string n)
    {
        int len = n.size();
        long long num = stoll(n);

        // 5 个候选
        vector<long long> cands;

        // 候选1: 位数-1的最大回文, e.g. len=4 -> 999
        cands.push_back((long long)pow(10, len - 1) - 1);

        // 候选2: 位数+1的最小回文, e.g. len=4 -> 10001
        cands.push_back((long long)pow(10, len) + 1);

        // 取前半段（含中间位）
        // e.g. "12345" -> 前缀 = "123"
        long long half = stoll(n.substr(0, (len + 1) / 2));

        // 候选3/4/5: 前半段 -1/0/+1 镜像
        for (int delta = -1; delta <= 1; delta++)
        {
            long long h = half + delta;        // 调整后的前半段
            string hs = to_string(h);
            string mirrored = hs;

            // 镜像后半段: 将前半段翻转拼到后面
            // 奇数长度跳过中间位，偶数长度全部镜像
            string rev = hs;
            reverse(rev.begin(), rev.end());
            // 奇数长度: 去掉 rev 的第一个字符（中间位不重复）
            mirrored += rev.substr(len % 2);   // len%2==1 跳过中间位

            cands.push_back(stoll(mirrored));
        }

        // 在所有候选中找最近的，距离相同取较小值
        long long ans = -1;
        for (long long c : cands)
        {
            if (c == num) continue;            // 不能等于 n 本身
            if (ans == -1 ||
                abs(c - num) < abs(ans - num) ||
                (abs(c - num) == abs(ans - num) && c < ans))
            {
                ans = c;
            }
        }

        return to_string(ans);
    }
};