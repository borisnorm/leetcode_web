class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while(!q.empty())
        {
          int cur = q.front();
          q.pop();

          for (int next : rooms[cur])
          {
              if (visited[next])
                continue;
              visited[next] = true;
              q.push(next);
          }
        }

        for (int i = 0; i < n; i++)
          if (!visited[i])
            return false;
        
        return true;
    }
};
/*
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n);

        dfs(rooms, 0, visited);

        for (auto v: visited)
        {
          if (!v)
            return false;
        }

        return true;
    }

    void dfs(vector<vector<int>>& rooms, int curRoom, vector<bool>& visited)
    {
        if (visited[curRoom])
          return;
 
        visited[curRoom] = true;
    
        for (int key: rooms[curRoom])
        {
           dfs(rooms, key, visited);
        }
    }
};

*/