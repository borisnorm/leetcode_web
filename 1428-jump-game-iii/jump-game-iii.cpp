class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        if (start < 0 || start >= n)
          return false;

        vector<bool> visited(n, 0);

        return dfs(arr, start, visited);
  }

   bool dfs(vector<int>& arr, int pos, vector<bool>& vis)
   {
       int n = arr.size();

       if (pos < 0 || pos >= n)
         return false;
       
       if (vis[pos])
         return false;
        
       vis[pos] = true;
       
       if (arr[pos] == 0)
         return true;

       bool leftFound = dfs(arr, pos-arr[pos], vis);
       bool rightFound = dfs(arr, pos+arr[pos], vis);

       return leftFound || rightFound;
   }
};

/*
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        if (start < 0 || start >= n)
          return false;

        vector<bool> visited(n, false);

        queue<int> q;
        visited[start] = true;
        q.push(start);

        while(!q.empty())
        {
           int cur_idx = q.front();
           q.pop();

           if (arr[cur_idx] == 0)
             return true;
           
           //性能瓶颈 每次调用都要不断构建新的
          // vector<int> dirs = {arr[cur_idx], -arr[cur_idx]};
          // for (int& dir: dirs)
           for (int dir: {arr[cur_idx], -arr[cur_idx]})
           {
              int nxt_idx = cur_idx + dir;
              if (nxt_idx < 0 || nxt_idx >= n)
                continue;
              
              if (visited[nxt_idx])
                continue;

              visited[nxt_idx] = true;
              q.push(nxt_idx);
           }
        }
        return false;
    }
};

*/