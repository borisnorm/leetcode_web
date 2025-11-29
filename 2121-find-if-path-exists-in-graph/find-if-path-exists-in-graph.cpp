class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

       vector<vector<int>> graph(n);

       for (auto e: edges)
       {
          int u = e[0];
          int v = e[1];

          graph[u].push_back(v);
          graph[v].push_back(u);
       }

       vector<int> visited(n, 0);
       queue<int> q;

       q.push(source);
       visited[source] = 1;

       while (!q.empty())
       {
          int cur = q.front();
          q.pop();

          if (cur == destination)
            return true;

          visited[cur] = 1;

          for (auto v: graph[cur])
          {
              if (!visited[v])
              {
                visited[v] = 1;
                q.push(v);
              }
          }
       }

       return false;

    }
};