class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        map<vector<int>, int> vec2freq;
        for (int i  = 0; i < m ; i++)
        {
           vec2freq[grid[i]]++;
        }

        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
           vector<int> colvec(m);
           for (int i = 0; i < m; i++)
           {
              colvec[i] = grid[i][j];
           }

           if (vec2freq.count(colvec))
           {
              cnt += vec2freq[colvec];
           }
        }

        return cnt;
    }
};