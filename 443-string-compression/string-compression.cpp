class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        
        int write = 0;
        int cnt = 1;

        for (int i = 1; i <= n; i++) {
            // 处理边界 or 不连续
            if (i == n || chars[i] != chars[i - 1]) {
                chars[write++] = chars[i - 1];  // 写字符

                if (cnt > 1) {
                    string num = to_string(cnt);
                    for (char c : num) {
                        chars[write++] = c;    // 写数字
                    }
                }

                cnt = 1;  // reset
            } else {
                cnt++;     // same char
            }
        }

        return write;
    }
};
