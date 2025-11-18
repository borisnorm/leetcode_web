class Solution {
public:
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
            int course = course_q.front();
            course_q.pop();

            cnt++;

            for (int next : graph[course])
            {
              indegree[next]--;
              if (indegree[next] == 0)
                course_q.push(next);
            }
        }

        return cnt == numCourses;
    }
};