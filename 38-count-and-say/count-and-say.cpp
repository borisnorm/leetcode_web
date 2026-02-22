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
        string res = "1";

        for (int i = 1; i < n; i++)
        {
           string next = "";
           int cnt = 1;

           // j = 0 作为基准 用于 与 cur j 进行对比, 所以 j = 1
           // 类似 lastC = res[0]; 的用法
           for (int j = 1; j < res.size(); j++)
           {
              if (res[j] == res[j-1])
                cnt++;
              else
              {
                //当前这次 去 push 前一次的结果
                next += to_string(cnt) + res[j-1];
                cnt = 1;
              }
           }

           next += to_string(cnt);
           next += res.back();   // j 在这里已经失效了, 

           res = next;     // 新的 s 经过压缩的 next, 不是 原来的 
        }

        return res;
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

