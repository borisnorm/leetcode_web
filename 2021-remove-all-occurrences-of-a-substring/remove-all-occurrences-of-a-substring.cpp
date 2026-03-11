class Solution {
public:
    string removeOccurrences(string s, string part) {
          int pLen = part.size();

         string st = "";
         for (char c : s)
         {
            st += c;
            // st.size()-pLen 是开始 删除的 pos 直到 末尾
            if (st.size() >= pLen &&
                st.substr(st.size()-pLen) == part)
            {
               //弹出 part 长度的字符
               //earse 从 pos 0 开始删除
               //st.size()-pLen 是开始 删除的 pos 直到 末尾
               //所以是 栈操作
               st.erase(st.size()-pLen);
            }
         }

         return st;
    }
};

/*
class Solution {
public:
    string removeOccurrences(string s, string part) {
         if (s.empty() || part.empty())
           return s;
        
         int n = s.size();
         int m = part.size();

         while (s.find(part) != string::npos)
         {
            int pos = s.find(part);

            s.erase(pos, m);
         }

         return s;
    }
};

*/