class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
         if (points.empty())
           return 0;
        
         int n = points.size();

         sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){return a[1] < b[1];});

         int nArrows = 1;
         int posArrow = points[0][1];
         for (int i = 0; i < n; i++)
         {
            int start = points[i][0];
            int end   = points[i][1];

            if (start <= posArrow)
              continue;
            else
            {
                nArrows++;
                posArrow = end;
            }
         }

         return nArrows;
    }
};