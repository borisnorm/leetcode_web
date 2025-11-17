class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int m = pattern.size();
        int n = s.size();

        int slow = 0;
        int fast = 0;

        unordered_map<char, string> char2word;
        unordered_map<string, char> word2char;

    
        while (fast < n)
        {
           int start = fast;
           while (fast < n && s[fast] != ' ')
             fast++;

           int len = fast - start;
           string word = s.substr(start, len);

           if (slow >= m)
             return false;

           char c = pattern[slow];

           if (char2word.count(c) && char2word[c] != word)
             return false;

           char2word[c] = word;

           if (word2char.count(word) && word2char[word] != c)
             return false;

           word2char[word] = c;

           fast++;
           slow++;

        }
         
        return slow == m;
    }
};
