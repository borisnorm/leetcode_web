class Solution {
public:

    string toGoatLatin(string sentence) {
        unordered_set<char> vowels = {
            'a','e','i','o','u',
            'A','E','I','O','U'
        };

        stringstream ss(sentence);
        string word;
        string res;
        int idx = 1;

        while (ss >> word) {
            // 判断首字母是否是元音
            if (vowels.count(word[0]) == 0) {
                // 辅音：首字母移到末尾
                word = word.substr(1) + word[0];
            }

            // 加 "ma"
            word += "ma";
            // 加 idx 个 'a'
            word += string(idx, 'a');

            // 拼接到结果
            if (!res.empty())
                res += " ";
            res += word;

            idx++;
        }

        return res;
    }

    /*
    string toGoatLatin(string sentence) {
        
        
        stringstream ss(sentence);
        string part;

        string res;
        int wordcnt = 0;
        while (ss >> part)
        {
           int m = part.size();
           if (m <= 0)
             continue;
        
           char c = part[0];
           if (!(tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) =='o' || tolower(c) == 'u'))
           {
              for (int i = 0; i < m-1; i++)
                  part[i] = part[i+1];
              part[m-1] = c;
           }

           part += "ma";

           wordcnt++;

           for (int i = 0; i < wordcnt; i++)
             part += 'a';

           res += part + ' ';

           part.clear();
        }

        // remove the last ' '
        if (!res.empty())
          res.pop_back();

        return res;
    }
    */
};