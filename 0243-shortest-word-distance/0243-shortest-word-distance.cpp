class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        
         int n = wordsDict.size();
         int p1 = -1;
         int p2 = -1;

         int minDist = INT_MAX;
         for (int i = 0; i < n; i++)
         {
            if (wordsDict[i] == word1)
            {
                 p1 = i;

                 if (p2 != -1)
                   minDist = min(minDist, abs(p1-p2));
            }
            else if (wordsDict[i] == word2)
            {
                 p2 = i;
                 if (p1 != -1)
                   minDist = min(minDist, abs(p1-p2));
            }
         }

         return minDist;
    }
};