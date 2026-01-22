class Solution {
public:
    
    vector<vector<int>> res;
    vector<int> comb;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }

    void dfs(vector<int>& cand, int pos, int target)
    {
       int n = cand.size();

       if (target == 0)
       {
          res.push_back(comb);
          return;
       }

       if (pos >= n)
         return;
       
       for (int i = pos; i < n; i++)
       {
          if (cand[i] > target)
            break;
          
          //错的离谱
          //if (i > pos && cand[pos] == cand[pos-1])
          //  continue;

          // 错误的 离谱
          //i 只要在 2 的位置才能工作  2 > 1, 那么 0, 1 的 重复 就无法处理 无法被 continue;
          //if (i > 1 && cand[i] == cand[i-1])
          //  continue;

          if (i > pos && cand[i] == cand[i-1])
            continue;

          comb.push_back(cand[i]);
          dfs(cand, i + 1, target - cand[i]);
          comb.pop_back();
       }
    }
};