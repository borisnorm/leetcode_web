class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.empty())
          return ans;

        int n = (int)s.size();

        int m = (int)words.size();
        int L = (int)words[0].size();

        int totalLen = m * L;

        if (n < totalLen)
          return ans;

        unordered_map<string, int> need;

        for (auto& w: words)
          need[w]++;

        for (int offset = 0; offset < L; offset++)
        {
            unordered_map<string, int> window;

            int left = offset;
            int count = 0;

            for (int right = offset; right + L <= n; right +=L)
            {
               string w = s.substr(right, L);

               if (!need.count(w))
               {
                  window.clear();
                  count = 0;
                  left = right + L;
                  continue;
               }

               // w 在dict 里面
               window[w]++;
               count++;
             
               // 某一个单词出现次数超过了 need 的要求,进行收缩
               while(window[w] > need[w])
               {
                  string lw = s.substr(left, L);
                  window[lw]--;
                  count--;
                  left += L;
               }

               if (count == m)
               {
                  ans.push_back(left);
                   
                  //后面还有解, 弹出左侧的解, 不然呢 count 永远等于 m 或是 count 用于不等于m 了
                  string lw = s.substr(left, L);
                  window[lw]--;
                  count--;
                  left += L;
               }
            }
        }

        return ans;
    }
};