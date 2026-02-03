class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        

        int m = s.size();
        // mark 标记为被设置成m 不是偶然
        // 如果设置为0, 下面的最后的for 循环就覆写 s 为全9了
        int mark = m;  

        for (int i = m-1; i >= 1; i--)
        {
            if (s[i-1] > s[i])
            {
                s[i-1]--;
                mark = i;
            }
        }

        // 填充 mark 位后的字符 全为 9
        for (int i = mark; i < m; i++)
          s[i] = '9';
        
        return stoi(s);

    }
};