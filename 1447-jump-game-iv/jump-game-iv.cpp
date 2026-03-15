class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        if (n == 1)
          return 0;
        unordered_map<int, vector<int>> val2idx;
        for (int i = 0; i < n; i++)
          val2idx[arr[i]].push_back(i);
        
        queue<int> q;
        vector<int> visited(n, 0);

        q.push(0);
        visited[0] = 1;

        int step = 0;
        while(!q.empty())
        {
          int q_sz = q.size();
          for (int i = 0; i < q_sz; i++)
          {
             int cur_idx = q.front();
             q.pop();

             if (cur_idx + 1 < n && !visited[cur_idx+1])
             {
                if (cur_idx + 1  == n - 1)
                  return step + 1;
                visited[cur_idx + 1] = 1;
                q.push(cur_idx + 1);
             }

             if (cur_idx - 1 >=0 && !visited[cur_idx-1])
             {
                if (cur_idx - 1 == n - 1)
                  return step + 1;
                visited[cur_idx - 1] = 1;
                q.push(cur_idx - 1);
             }

             int val = arr[cur_idx];
             if (val2idx.count(val))
             {
                for (int j : val2idx[val])
                {
                   if (!visited[j])
                   {
                     if (j == n - 1)
                       return step + 1;
                     visited[j] = 1;
                     q.push(j);
                   }
                }
                val2idx.erase(val);
             }

          }
          
          step++;
        }

        return -1;
    }
};