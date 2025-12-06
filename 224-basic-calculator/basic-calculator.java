class Solution {
    public int calculate(String s) {
        int res = 0;
        int sign = 1;
        int num = 0;

        Stack<Integer> st = new Stack<Integer>();
        for (int i = 0; i < s.length(); i++)
        {
            char c = s.charAt(i);
            if (Character.isDigit(c))
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
            else if (c == '(')
            {
                st.push(res);
                st.push(sign);

                num = 0;
                res = 0;
                sign = 1;
            }
            else if (c == ')')
            {
                res += sign * num;
                num = 0;

                int preSign = st.peek(); st.pop();
                int preRes  = st.peek(); st.pop();

                res = preRes + preSign * res;
                
            }

        }

        res += sign * num;
        return res;
    }
}

