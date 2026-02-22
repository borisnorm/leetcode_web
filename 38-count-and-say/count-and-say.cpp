/*
class Solution {
public:
    string countAndSay(int n) {
        if (n == 0)
          return "";
        
        string res = "1";

        for (int i = 1; i < n; i++)
        {
           string tmp = "";
           int j = 0;
           int n = res.size();
           while (j < n)
           {
              char c = res[j];
              int cnt = 0;
              while (j < n && res[j] == c)
              {
                 j++;
                 cnt++;
              }

              tmp += to_string(cnt) + c;
           }  

           res = tmp;
        }

        return res;
    }
};
*/

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 1; i < n; i++)
        {
           string next = "";
           int cnt = 1;

           for (int j = 1; j < s.size(); j++)
           {
              if (s[j] == s[j-1])
                cnt++;
              else
              {
                next += to_string(cnt);
                next += s[j-1];
                cnt = 1;
              }
           }

           next += to_string(cnt);
           next += s.back();   // j 在这里已经失效了, 

           s = next;     // 新的 s 经过压缩的 next, 不是 原来的 
        }

        return s;
    }

    //错误的思路
    //11
    //211
    //3211
    //43211
    //543211
    //6543211
    //76543211
    //876543211
    //9876543211
    //109876543211
    //11109876543211
    //1211109876543211
    //131211109876543211
};

