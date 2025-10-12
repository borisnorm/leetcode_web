class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> ops_stack;

        for (auto &t : tokens)
        {
          if (t == "+" || t == "-" || t == "*" || t == "/")
          {
             long long a = ops_stack.top(); 
             ops_stack.pop();
             long long b = ops_stack.top();
             ops_stack.pop();
             long long res = 0;

             if (t == "+")
               res = b + a;
             else if (t == "-")
               res = b - a;
             else if (t == "*")
               res = b*a;
             else if (t == "/")
               res = b/a;
             
            ops_stack.push(res);
             
          }
          else
          {
             ops_stack.push(stoll(t));
          }
        }

        return ops_stack.top();
    }
};