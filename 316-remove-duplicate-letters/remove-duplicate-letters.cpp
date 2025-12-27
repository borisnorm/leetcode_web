class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector<int> freq(26, 0);
        vector<bool> inStack(26, false);
        string st;

        for (char c : s)
          freq[c-'a']++;
        
        int n = s.size();

        for (char c: s)
        {
           int idx = c - 'a';

           //频率自减
           freq[idx]--;
          
           // 去重
           if (inStack[idx])
             continue;

          // 弹栈
          while (!st.empty() && c < st.back() && freq[st.back()-'a'] > 0)
          {
            int preIdx = st.back() - 'a';
            inStack[preIdx] = false;
            st.pop_back();
          }

           inStack[idx] = true;
           st.push_back(c);
        }

        return st;
    }
};