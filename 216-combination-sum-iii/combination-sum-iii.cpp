class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> track;
        vector<vector<int>> res;
        backtrack(k, 1, n, track, res);
        return res;
    }    
    
    void backtrack(int k, int start, int sum, vector<int>& track, vector<vector<int>>& res)
    {
        if (track.size() == k && sum == 0)
        {
            res.push_back(track);
            return;
        }
       
        int const MAX_NUM = 9;
        if (k - track.size() > MAX_NUM - start + 1)
          return;

        for (int i = start; i <= MAX_NUM; i++)
        {
           if (i > sum)
             return;
        
           track.push_back(i);

           backtrack(k, i+1, sum-i, track, res);

           track.pop_back();
        }
    
    }
};