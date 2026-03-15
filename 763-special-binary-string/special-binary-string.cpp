class Solution {
public:
    string makeLargestSpecial(string s) {
        int cnt = 0;
        int i = 0;
        
        vector<string> parts;

        for (int j = 0; j < s.size(); j++)
        {
           cnt += (s[j] == '1') ? 1 : -1;

           // == 0说明 当前 substring 是一个 special stirng
           // 去掉 开头 与 结尾
           if (cnt == 0)
           {
              //正常取值范围是 [i, j] , 去掉首尾 后是  [i+1, j-1]
              string inner = makeLargestSpecial(s.substr(i+1, j-1-i));

              parts.push_back("1" + inner + "0");

              i = j + 1;
           }
        }

        // 降序排列
        sort(parts.begin(), parts.end(), greater<string>());

        string res = "";
        for (auto part: parts)
          res += part;

        return res;
    }
};