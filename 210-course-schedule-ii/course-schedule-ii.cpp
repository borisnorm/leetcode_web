class Solution {
public:
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

         vector<vector<int>> adj(numCourses);
         vector<int> indegree(numCourses, 0);

         for (auto& pre: prerequisites)
         {
            // u -> v  
            // 字面上 a --依赖于--> b
            // 形式上是  b (u) --> a (v) 
            int a = pre[0];
            int b = pre[1];

            adj[b].push_back(a);
            indegree[a]++;
            
            // 彻底写反了
            //adj[a].push_back(b);
            //indeg[b]++;
         }

         queue<int> course_queue;
         for (int i = 0 ; i < numCourses; i++)
           if (indegree[i] == 0)
             course_queue.push(i);
        
        vector<int> order;
        while (!course_queue.empty())
        {
          int u = course_queue.front();
          course_queue.pop();
          order.push_back(u);
          // u --> v
          for (int v: adj[u])
          { 
             indegree[v]--;
             if (indegree[v]==0)
               course_queue.push(v);
          }
        }

        if (order.size() != numCourses)
          return {};

        return order;
    }
};