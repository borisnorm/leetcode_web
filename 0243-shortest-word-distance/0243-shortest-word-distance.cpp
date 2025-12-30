class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
         vector<int> word1_idx;
         vector<int> word2_idx;

         int n = wordsDict.size();
         for (int i = 0; i < n; i++)
         {
            string word = wordsDict[i];
            if (word == word1)
              word1_idx.push_back(i);
            else if (word == word2)
              word2_idx.push_back(i);
         }

         int w1_sz = word1_idx.size();
         int w2_sz = word2_idx.size();
         int minDist = INT_MAX;
         for (int i = 0; i < w1_sz; i++)
         {
            for (int j = 0; j < w2_sz; j++)
            {
                minDist = min(minDist, abs(word1_idx[i] - word2_idx[j]));
            }
         }

         return minDist;
    }
};