class Solution {
public:
    // 与 698 相同
    bool makesquare(vector<int>& matchsticks) {

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        int sum = 0;
        for (int matchstick: matchsticks)
          sum += matchstick;
        
        if (sum % 4 != 0)
          return false;
        
        int target = sum / 4;
        if (matchsticks[0] > target) 
          return false;
        
        vector<int> side(4, 0);
        int idx = 0;
        return dfs(matchsticks, idx, side, target);
    }

    bool dfs(vector<int>& matchsticks, int idx, vector<int>& side, int target)
    {
        if (idx == matchsticks.size())
        {
           if (side[0] == target && side[1] == target && side[2] == target)
             return true;
        }

        //轮询4条边
        for (int i = 0; i < 4; i++)
        {
           if (side[i] + matchsticks[idx] > target)
             continue;
          
           if (i > 0 && side[i] == side[i-1])
             continue;

           side[i] += matchsticks[idx];

           if (dfs(matchsticks, idx+1, side, target))
             return true;
          // 回溯
           side[i] -= matchsticks[idx];
        }
        return false;
    }
};