class Solution {
public:
    int calculate(string s) {
        long long res = 0;
        long long num = 0;  //⚠ 结果在 int 范围 ≠ 中间过程在 int 范围。 num 也是一样的
        int  sign = 1;

        stack<int> st;

        for (char c: s)
        {
           if (isdigit(c))
           {
              num = num * 10 + (c - '0');
           }
           else if (c == '+')
           {
              res += sign * num;
              num = 0;
              sign = 1;
           }
           else if (c == '-')
           {
              res += sign * num;
              num = 0;
              sign = -1;
           }
           // 1 + (12 - 3) + 1
           else if (c == '(')
           {
              st.push(res);
              st.push(sign);

              res = 0;
              sign = 1;
              
              //也可以在这里设置 num 为0的
              num = 0;
           }
           else if (c == ')')
           {
              res += sign * num;

              sign = 1;
              num = 0;

              int prevSign =  st.top(); st.pop();
              int prevRes  =  st.top(); st.pop();

              res = prevRes + prevSign * res;
           }

        }

        // 最后把剩余的数字加上, 循环到最后的 数字 或是 ) 就退出了
        res += sign * num;

        return res;
    }
};