class Solution {
public:
    string removeOuterParentheses(string s) {
        
         int n = s.size();
         
         string res;
         stack<char> st;

         int start = 0;
         int balance = 0;
         for (int i = 0; i < n; i++)
         {
            balance += (s[i] == '(') ? 1 : -1;
            if (balance < 0)
              break;
            
            if (balance == 0)
            {
               int len = i - start - 1;
               string inner = s.substr(start+1, len);
               res += inner;
               start = i + 1;
            }
         }

         return res;   
    }
};