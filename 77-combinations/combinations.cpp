class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return res;
    }

    void backtrack(int n, int k, int start)
    {
       if (track.size() == k)
       {
          res.push_back(track);
          return;
       }

      /*
       // 不同的表达方式 选择一个就行
       if (track.size() + (n - start + 1) < k) 
           return;
      */

      if (k - track.size() > n - start + 1)
         return;

       for (int i = start; i <= n; i++)
       {
          track.push_back(i);
          backtrack(n, k, i+1);  //这里是 i+1 不是 start + 1
          track.pop_back();
       }
    }
};