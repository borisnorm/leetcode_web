
class Solution {
public:

    int digits(int n)
    {
       int d = 0;
       while (n > 0)
       {
          d++;
          n /= 10;
       }

       return d;
    }
    vector<string> splitMessage(string message, int limit) {
        int n = message.size();

        for (int k = 1; k <= n; k++)
        {
          // 总段数 
          int dk = digits(k); 
          int used = 0;
          bool valid = true;

          for (int i = 1; i <= k; i++)
          {
            // suffic = "/" + strc(k) + strk(i)
            int suffix_len = digits(i) + 3 + dk;
            int avail = limit - suffix_len;

            if (avail <= 0)
            {
              valid = false;
              break;
            }

            used += avail;
          }

          if (!valid || used < n)
            continue;  // k 不够大 继续试

          vector<string> res;
          int pos = 0;

          for (int i = 1; i <= k; i++)
          {
             int suffix_len = digits(i) + 3 + dk;
             int avail = limit - suffix_len;

             string part = message.substr(pos, avail);

             pos += avail;

             res.push_back(part + "<" + to_string(i) + "/" + to_string(k) + ">");
          }

          return res;
        }

        return {};
    }
};
