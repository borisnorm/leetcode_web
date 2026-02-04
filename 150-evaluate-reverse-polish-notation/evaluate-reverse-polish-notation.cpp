class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<long long> st;
        for (string& t: tokens)
        {
            if (t == "+" || t == "-" || t == "*" || t == "/")
            {
                //注意顺序 第一个 top 与 pop 出来的是 b, 不是 a
                long long b = st.top(); 
                st.pop();

                long long a = st.top();
                st.pop();

                long long res = 0;
                
                if (t == "+")
                  res = a + b;
                 else if (t == "-")
                  res = a - b;
                 else if (t == "*")
                  res = a * b;
                 else if (t == "/")
                  res = a / b;
                
                st.push(res);
            }
            else
            {
               st.push(stoll(t));
            }
        }

        return (int)st.top();
    }
};