class Solution {
public:
    int calculate(string s) {

       int n = s.size();
    
       int num = 0;
       long long res = 0;
       char op = '+';

       stack<long long> st;

        // 1. op + num as unit to be hanled 
        // 2. num and temp res is stored in stack
        // 3. collect the stack

       for (int i = 0; i < n; i++)
       {
          char c = s[i];

          if (isdigit(c))
            num = num * 10 + (c - '0');
          // operator 运算法 or 字符串 末尾
          
          //为了处理最后一个数, 因为最后结尾的都是数字, op 就会是一个数字字符 c 
          if ((!isdigit(c) && c != ' ') || (i == n-1))
          {
             if (op == '+')
               st.push(num);
             else if (op == '-')
               st.push(-num);
             else if (op == '*')
             {
               int preNum = st.top();
               st.pop();

               st.push(preNum * num);
             }
             else if (op == '/')
             {
                int preNum = st.top();
                st.pop();
                st.push(preNum/num);
             }

             op = c;
             num = 0;
          }
       }

       while (!st.empty())
       {
          res += st.top();
          st.pop();
       }

       return (int)res;
    }
};