class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>  dict(bank.begin(), bank.end());

        if (!dict.count(endGene))
          return -1;
        
        queue<pair<string, int>> q;
        q.push({startGene, 0});

        vector<char> genes = {'A', 'C', 'G', 'T'};

        while(!q.empty())
        {
           auto [cur, steps] = q.front();
           q.pop();

           if (cur == endGene)
             return steps;
         
           for (int i = 0; i < 8; i++)
           {           
              char old = cur[i];
              
              for (char g: genes)
              {
                if (g == old)
                  continue;
                
                cur[i] = g;

                if (dict.count(cur))
                {
                   q.push({cur, steps + 1});
                   dict.erase(cur);
                }
              }

              cur[i] = old;
           }
        }

        return -1;
    }
};