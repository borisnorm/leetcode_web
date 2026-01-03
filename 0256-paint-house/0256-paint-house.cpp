class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0)
          return 0;
        
        int r = costs[0][0];
        int b = costs[0][1];
        int g = costs[0][2];
        
        for (int i = 1; i < n; i++)
        {
           int nr = costs[i][0] + min(b, g);
           int nb = costs[i][1] + min(r, g);
           int ng = costs[i][2] + min(r, b);

           r = nr; 
           b = nb; 
           g = ng;
        }

        return min({r, g, b});
    }
};