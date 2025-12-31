class Solution {
public:
    string smallestSubsequence(string s) {
        
        //string st;
        int n = s.size();
        vector<bool> inStack(26, false);
        vector<int>  freq(26, 0);
        stack<int> st;

        for (char c: s)
          freq[c-'a']++;

        for (int i = 0; i < n; i++)
        {
           int idx = s[i] - 'a';
          
           freq[idx]--;
           // remove the same 
           if (inStack[idx])
             continue;
          
           while (!st.empty())
           {
             int prevIdx = s[st.top()] - 'a';
             if(freq[prevIdx] > 0 && s[i] < s[st.top()])
             {
               st.pop();
               inStack[prevIdx] = false;
             }
             else
               break;
           }
        
           inStack[idx] = true;
           st.push(i);
        }

        string res;
        while (!st.empty())
        {
           res+= s[st.top()];
           st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};