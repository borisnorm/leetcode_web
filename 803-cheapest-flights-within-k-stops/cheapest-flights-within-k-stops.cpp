class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    
         unordered_map<int, vector<pair<int, int>>> graph;



         for (auto& flight: flights)
         {
            int src = flight[0];
            int dst = flight[1];
            int cost = flight[2];

            graph[src].push_back({dst, cost});
         }

         vector<int> dist(n, INT_MAX);
         queue<pair<int, int>> q;
         q.push({src, 0});

         dist[src] = 0;
         int step = 0;

         while (!q.empty() && step <= k)
         {  
            int q_sz = q.size();

            vector<int> tempDist = dist;
            for (int i = 0; i < q_sz; i++)
            {
               auto [u, cost] = q.front();
               q.pop();

               for (auto [v, cost]: graph[u])
               {
                 if (tempDist[v] > dist[u] + cost)
                 {
                    tempDist[v] = dist[u] + cost;
                    q.push({v, dist[v]});
                  }
       
               }
              
            }

            dist = tempDist;

            step++;

         }

         
         return dist[dst] == INT_MAX ? -1 : dist[dst];
    }


    /*
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;

        for (int step = 0; step <= k; step++)
        {
          vector<int> prev = dist;
          for (auto& e: flights)
          {
             int u = e[0];
             int v = e[1];
             int w = e[2];

             if (prev[u] == INT_MAX)
               continue;
            
             dist[v] = min(dist[v], prev[u] + w);
          }
        }

        return dist[dst] == INT_MAX ? -1 :  dist[dst];
    }

    */
};