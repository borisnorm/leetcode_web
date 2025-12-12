class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;  // 字符, 连续次数
        
        for (char c: s)
        {
           if (!st.empty() && st.back().first == c)
           {  
               st.back().second++;
               if (st.back().second == k)
               {
                  st.pop_back();
               }
           }
           else
           {
              st.push_back({c, 1});
           }
        }

        string res;
        for (auto& [c, cnt] : st)
          res.append(cnt, c);
        
        return res;
    }
};