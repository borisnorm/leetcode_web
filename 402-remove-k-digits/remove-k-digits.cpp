class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.size();
        if (n <= 0 || n < k)
          return "0";
        
        string st;
        for (int i = 0; i < n; i++)
        {
           char c = num[i];

           while (!st.empty() && k > 0 &&  c < st.back())
           {
              st.pop_back();
              k--; 
           }
        
           st.push_back(c);
        }

        while (k > 0)
        {
           st.pop_back();
           k--;
        }

        int i = 0;
        while (i < n && st[i] == '0') 
          i++;
        
        string num_str = st.substr(i);

        return (num_str.empty()) ? "0" : num_str;

    }
};