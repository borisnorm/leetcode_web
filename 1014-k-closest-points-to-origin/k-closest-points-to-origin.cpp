class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto dist2 = [] (long long x, long long y){
           return 1LL*x*x + 1LL*y*y;
        };

        priority_queue<pair<long long, int>> points_queue;

        for (int i = 0; i < points.size(); i++)
        {
           long long dist = dist2(points[i][0], points[i][1]);

           if (points_queue.size() < k)
             points_queue.emplace(dist, i);
           else if (dist < points_queue.top().first)
           {
              points_queue.pop();
              points_queue.emplace(dist, i);
           }
        }

        vector<vector<int>> res;
        res.reserve(k);

        while(!points_queue.empty())
        {
          pair<long long, int> dist_idx_pair = points_queue.top();
          points_queue.pop();
          int idx = dist_idx_pair.second;
          res.push_back(points[idx]);
        }

        return res;
    }
};