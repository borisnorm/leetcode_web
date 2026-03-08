class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        queue<int> q;
        vector<bool> visited(n, false);
        int nProvince = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {                
                q.push(i);
                visited[i] = true;
                nProvince++;

                while(!q.empty())
                {
                    int u = q.front();
                    q.pop();

                    for (int v = 0; v < n; v++)
                    {
                       if (isConnected[u][v] == 1 && !visited[v])
                       {
                          visited[v] = true;
                          q.push(v);
                       }
                    }
                }
            }
        }

        return nProvince;
    }
};