class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<char, string> char2morse = {
         {'a',  ".-"},
         {'b',  "-..."},
         {'c',  "-.-."},
         {'d',  "-.."},
         {'e',  "."},
         {'f',  "..-."},
         {'g',  "--."},
         {'h',  "...."},
         {'i',  ".."},
         {'j',  ".---"},
         {'k',  "-.-"},
         {'l',  ".-.."},
         {'m',  "--"},
         {'n',  "-."},
         {'o',  "---"},
         {'p',  ".--."},
         {'q',  "--.-"},
         {'r',  ".-."},
         {'s',  "..."},
         {'t',  "-"},
         {'u',  "..-"},
         {'v',  "...-"},
         {'w',  ".--"},
         {'x',  "-..-"},
         {'y',  "-.--"},
         {'z',  "--.."}
        };

        vector<string> transform_words;

        for (string word: words)
        {
           string tranform;
           for (char c: word)
             tranform += char2morse[c];
        
           transform_words.push_back(tranform);
        }

        unordered_set<string> transform_set(transform_words.begin(), transform_words.end());

        return transform_set.size();

    }
};