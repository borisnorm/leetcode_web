class Solution {
public:
    int longestStrChain(vector<string>& words) {
         //按长度升序排列
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;

        int maxLen = 1;

        for(string& word: words)
        {
           dp[word] = 1;

           for (int i = 0; i < word.size(); i++)
           {
              string pre_word = word.substr(0, i) + word.substr(i+1, word.size());

              if (dp.count(pre_word))
              {
                  dp[word] = max(dp[word], dp[pre_word] + 1);
              }
           }

           maxLen = max(maxLen, dp[word]);
        }

        return maxLen;
    }
};