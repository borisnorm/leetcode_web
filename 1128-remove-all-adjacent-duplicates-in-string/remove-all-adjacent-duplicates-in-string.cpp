class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        int n = s.size();
        if (n == 0)
          return res;

        stack<char> st;
        for (int i = 0; i < n; i++)
        {
           char c = s[i];
           bool isDuplicate = false;

           if (!st.empty() && s[i] == st.top())
           {
              st.pop();
              isDuplicate = true;
           }

           if (!isDuplicate)
             st.push(c);
        }

        while(!st.empty())
        {
           char c = st.top();
           st.pop();

           res.insert(res.begin(), c);
        }

        return res;
    }
};