class Solution {
public:
    int maxDepth(string s) {
        
        int maxDep = 0;
        stack<char> st;

        for (char c: s)
        {
           if (c == '(')
           {
              st.push(c);
              maxDep = max(maxDep, (int)st.size());
           }
           else if (c == ')')
           {
              st.pop();
           }
        }
        return maxDep;
    }
};