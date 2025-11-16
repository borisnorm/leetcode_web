class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1)
          return 0;

        vector<int> minDist(n, INT_MAX);
        vector<bool> inMST(n, false);

        minDist[0] = 0;
        int res = 0;

        for (int i = 0; i < n; i++)
        {
           int u;
           int minVal = INT_MAX;
           int minIdx = -1;
           for (int j = 0; j < n; j++)
           {
              // this place u = j - 1; j is the current val
              if (!inMST[j] && minDist[j] < minVal)
              {
                  minVal = minDist[j];
                  minIdx = j;
              }
           }
    
          // 1st u = j
          u = minIdx;
          inMST[u] = true;
          res += minDist[u];

          for (int v = 0; v < n; v++)
          {
            if (!inMST[v])
            {
                int w = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                if (w < minDist[v])
                  minDist[v] = w;
            }
          }

        }

       return res;
    }
};