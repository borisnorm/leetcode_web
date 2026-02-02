class Solution {
public:
        vector<string> res;
        vector<string> path;

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0);
        return res;
    }

    void backtrack(const string& s, int start)
    {
       if (path.size() == 4)
       {
          //start 是 切分线的位置, start 已经到了s的末尾
          if (start == s.size())
            res.push_back(path[0] + "." +
                          path[1] + "." + 
                          path[2] + "." +
                          path[3]);
        
          return;
       }

       //还剩下多少字符
       int remaining = s.size() - start;
       //还需要多少段
       int needed = 4 - path.size();

       // 每个段最少1个字符, 也就是 最小需要 need 个字符, 或是 remaining 比 这最少需要的都少, 那就不用比了
       // 每个段最多3个字符, 如果剩余的字符数 比 所需段数可达到的最大的字符长度 都大, 也不用比了, 前面切割错了  
       if (remaining < needed || remaining > needed * 3)
         return;
        
       int num = 0;
       
       // i + len, 是 i 的 [i, i+len) 左开 右闭区间, 因为包括了 i,
       for (int i = start; i < s.size() && i < start + 3; i++)
       {
          //start 是旧值
          //i == start → segment 长度是 1，例如 "0"
          //i > start → segment 长度大于 1，例如 "01", "012"
          if (i > start && s[start] == '0')
            break;

           // 构建[0--255] 这个数字 one by one
           // 可以构建 [2] [25] [255],
           // 如果数值不超过255, 就继续下面的 backtrack, 否则退出
           num = num * 10 + (s[i] - '0');
           if (num > 255)
             break;
        
           //对于[start, i], i-start+len才是长度
           path.push_back(s.substr(start, i - start +1 ));
           backtrack(s, i+1);
           path.pop_back();
       }

    }
};