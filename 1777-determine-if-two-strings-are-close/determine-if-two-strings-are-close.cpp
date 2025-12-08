class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();
        if (m != n)
          return false;

        unordered_map<char, int> word1_char2freq;
        unordered_map<char, int> word2_char2freq;

        for (char c: word1)
          word1_char2freq[c]++;
        for (char c: word2)
          word2_char2freq[c]++;

        vector<int> word1_freq;
        for (auto it: word1_char2freq)
        {
            if (!word2_char2freq.count(it.first))
              return false;

            word1_freq.push_back(it.second);
            
        }

        vector<int> word2_freq;
        for (auto it: word2_char2freq)
        {
            if (!word1_char2freq.count(it.first))
              return false;

            word2_freq.push_back(it.second);
        }

        sort(word1_freq.begin(), word1_freq.end());
        sort(word2_freq.begin(), word2_freq.end());

        return word1_freq == word2_freq;
    }
};