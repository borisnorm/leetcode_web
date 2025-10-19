class Solution {
public:
    string decodeString(string s) {
        string res="";
        if (s.empty())
          return res;

        stack<string> str_stack;
        stack<int> num_stack;

        int cur_num = 0;
        string cur_str ="";

        for (char c : s)
        {
           int digit;
           if (isdigit(c))
           {
             cur_num = cur_num * 10 + (c - '0');
           }
           else if (isalpha(c))
           {
             cur_str +=c;
           }
           else if (c == '[')
           {
              // clear
              num_stack.push(cur_num);
              str_stack.push(cur_str);
            
              cur_num = 0;
              cur_str.clear();
           }
           else if (c == ']')
           {
              int repeated_cnt = num_stack.top();
              num_stack.pop();
              string pre_str = str_stack.top();
              str_stack.pop();

              string repeated_str = "";
              for (int i = 0; i < repeated_cnt; i++)
                repeated_str += cur_str;

              cur_str = pre_str + repeated_str;
           }
          
        } 

        return cur_str;
    }
};