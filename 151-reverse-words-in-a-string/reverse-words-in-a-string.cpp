class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
          return "";
    
        string res;
        vector<string> words;

        int n = (int)s.size();
        int i = 0;

        //前置 leading space ' ', hello 前面的空格
        while (i < n && s[i] == ' ')
          i++;

        while (i < n)
        {
           int start = i;
           while (i < n && s[i] != ' ')
             i++;
           int end = i;
           string word = s.substr(start, end - start);
           words.push_back(word);
           
           //处理 单词间空格 以及 后置 leading space ' ', world 后来的空格
           while (i < n && s[i] == ' ')
            i++;
        }

        reverse(words.begin(), words.end());
        for (int i = 0; i < words.size(); i++)
        {
            if (i > 0)
              res += ' ';

            res += words[i];
        }

        return res;
    }
};