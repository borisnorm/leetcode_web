class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        //BFS
        if (source == target)
          return 0;
          
        int n = routes.size();


        // 某一个 stop  与 经过这个 stop 的 所有 route 路线的映射
        unordered_map<int, vector<int>>  stop2route;

        for (int i = 0; i < n; i++)
        {
            for (int stop: routes[i])
            {
                stop2route[stop].push_back(i);
            }
        }

        if (!stop2route.count(source) || !stop2route.count(target))
          return -1;

        vector<int> visited_route(n, 0);

        // route queue
        queue<int> q;
        for (int r : stop2route[source])
        {
          q.push(r);
          visited_route[r] = 1;
        }

        int bus = 1;

        // BFS on route
        while(!q.empty())
        {
          int q_sz = q.size();

          for (int i = 0; i < q_sz; i++)
          {
             int curR = q.front();
             q.pop();

             for (int stop: routes[curR])
             {
                if (stop == target)
                  return bus;

                auto &nextRoutes = stop2route[stop];
                for (int nextR : nextRoutes)
                {
                    if (!visited_route[nextR])
                    {
                      visited_route[nextR] = 1;
                      q.push(nextR);
                    }
                }
                nextRoutes.clear();  
                
             }
          } 

          bus++;
        } 

        return -1;

    }
};