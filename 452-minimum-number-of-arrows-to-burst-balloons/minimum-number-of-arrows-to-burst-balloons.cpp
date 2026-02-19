class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
         if (points.empty())
           return 0;
        
         int n = points.size();

         sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){return a[1] < b[1];});

         int nArrows = 1;
         int lastArrowEnd = points[0][1];
         for (int i = 1; i < n; i++)
         {
            int start = points[i][0];
            int end   = points[i][1];

            // 当前 balloon 与 前一个 有重叠, 那么不用 增加 arrow 数量
            if (start <= lastArrowEnd)
              continue;
            else
            {
                nArrows++;
                lastArrowEnd = end;
            }
         }

         return nArrows;
    }
};