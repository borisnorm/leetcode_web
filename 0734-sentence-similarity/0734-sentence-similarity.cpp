class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        multiset<pair<string, string>> similar_set;

        int m = sentence1.size();
        int n = sentence2.size();
        if (m != n)
          return false;

        for (auto pair: similarPairs)
        {
          similar_set.insert({pair[0], pair[1]});
          similar_set.insert({pair[1], pair[0]});
        }

        for (int i = 0; i < n; i++)
        {
            if (sentence1[i] == sentence2[i])
              continue;

            if (!similar_set.count({sentence1[i], sentence2[i]}))
              return false;
        }

        return true;
    }
};