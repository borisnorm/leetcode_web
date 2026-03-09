class Solution {
public:
    // Time: O(V+E), Space: O(V+E)
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

          vector<vector<int>> adj(numCourses);

          for(auto prereq: prerequisites)
          {
             int a = prereq[0];
             int b = prereq[1];

             adj[b].push_back(a); 
          }

          vector<int> color(numCourses, 0);
          for (int i = 0; i < numCourses; i++)
          {
              if (!dfs(adj, i, color))
                return false;
          }

          return true;
    }

    // color 0-not_visited 1. in-progress, 2-completed
    bool dfs(vector<vector<int>>& adj, int u, vector<int>& color)
    {
       //if (color[u] == 1)
       //     return false;
       color[u] = 1;

        for (int v : adj[u])
        {
          if (color[v] == 1)
            return false;

          if (color[v] == 0)
          {
            if (!dfs(adj, v, color))
              return false;
          }
        }

        color[u] = 2;
        return true;
    }
};
/*
class Solution {
public:
    // Time: O(V+E), Space: O(V+E)
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        //1. graph adj list  b->a
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];

            graph[prereq].push_back(course);
            indegree[course]++;
        }

        //2. push indegree 0 courses
        queue<int> course_q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
              course_q.push(i);
        }
          
        //3. taken prequsites courese and re-push indgree 0 course
        int cnt = 0;
        while (!course_q.empty())
        {
            int prereqs = course_q.front();
            course_q.pop();

            cnt++;

            for (int pre : graph[prereqs])
            {
              indegree[pre]--;
              if (indegree[pre] == 0)
                course_q.push(pre);
            }
        }

        return cnt == numCourses;
    }
};
*/