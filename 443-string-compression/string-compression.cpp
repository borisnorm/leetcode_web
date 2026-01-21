class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int read = 0;
        int write = 0;

        // Time Complexity:  O(n)
        // Space Complexity: O(1)
        while (read < n)
        {
            // go through the read part
           int start = read;
           char c = chars[start];
           while (read < n && chars[read] == c)
           {
              read++;
           }
           int end = read;
           int cnt = end - start; // [start, end);
            
           // write char
           chars[write++] = c;

           // write cnt
           if (cnt > 1)
           {
              string cnt_str = to_string(cnt);
              for (char digit : cnt_str)
                chars[write++] = digit;
           }
        }

        return write;
    }
/*
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

                    // cnt 的 num 的 str 也是按 character 去写的
                    for (char c : num)
                        chars[write++] = c;    // 写数字
                }

                cnt = 1;  // reset
            } 
            else 
            {
                cnt++;     // same char
            }
        }

        return write;
    }
*/
};
