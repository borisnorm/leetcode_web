class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int diff[101] = {};
        for (auto& p: logs)
        {
           int b = p[0] - 1950;
           int d = p[1] - 1950;

           diff[b]++;
           diff[d]--;
        }

        int maxPop = 0;
        int maxPopYear = 1950;

        int cur = 0;

        for (int i = 0; i < 101; i++)
        {
           cur += diff[i];
           if (cur > maxPop)
           {
              maxPop = cur;
              maxPopYear = 1950 + i;
           }
        }

        return maxPopYear;
    }
};