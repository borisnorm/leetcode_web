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

        vector<int> room = rooms[curRoom];

        visited[curRoom] = true;
    
        for (int key: room)
        {
           dfs(rooms, key, visited);
        }
    }
};