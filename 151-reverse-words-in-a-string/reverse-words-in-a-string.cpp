class Solution {
public:
    string reverseWords(string s) {
        string res;
        vector<string> words;

        if (s.empty())
          return res;

        int n = (int)s.size();
        int i = 0;

        while (i < n && s[i] == ' ')
          i++;

        while (i < n)
        {
           int start = i;
           while (i < n && s[i] != ' ')
             i++;
           string word = s.substr(start, i - start);
           words.push_back(word);
           
           while (i < n && s[i] == ' ')
            i++;
        }

        reverse(words.begin(), words.end());

        string ans;
        for (int i = 0; i < words.size(); i++)
        {
            if (i > 0)
              ans += ' ';

            ans += words[i];
        }

        return ans;

        
    }
};