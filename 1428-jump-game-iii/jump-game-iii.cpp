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

        int nxt_idx = 0;
        while(!q.empty())
        {
           int cur_idx = q.front();
           q.pop();

           if (arr[cur_idx] == 0)
             return true;
           
           vector<int> dirs = {arr[cur_idx], -arr[cur_idx]};
           for (int dir: dirs)
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