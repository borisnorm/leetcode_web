class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> diag;
        
        int m = nums.size();
        int maxD = 0;

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = 0; j < (int)nums[i].size(); j++)
            {
               int d = i + j;
               diag[d].push_back(nums[i][j]);
               maxD = max(maxD, d);
            }
        }

        vector<int> res;
        for (int d = 0; d <= maxD; d++)
        {
           auto it = diag.find(d);
           if (it == diag.end())
             continue;
            
           auto& v = it->second;

           res.insert(res.end(), v.begin(), v.end()); 
        }

        return res;
        
    }
};