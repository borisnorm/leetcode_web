class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows <= 0)
          return {};        

        vector<vector<int>> res;
    
        res.push_back({1});
        if (numRows == 1)
          return res;

        res.push_back({1, 1});
        if (numRows == 2)
          return res;

        for (int i = 2; i < numRows; i++)
        {
            vector<int> row;
            vector<int> pre = res[i-1];
            int n = pre.size();

            row.push_back(1);
            
            for (int j = 1 ; j < n; j++)
            {
               row.push_back(pre[j-1] + pre[j]);   
            }

            row.push_back(1);
            

            res.push_back(row);         
        }

        return res;
    }
};