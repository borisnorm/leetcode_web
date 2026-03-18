class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {

        sort(matchsticks.begin(), matchsticks.end());

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

        bool res = false;
        for (int i = 0; i < 4; i++)
        {
           if (side[i] + matchsticks[idx] > target)
             continue;
          
           if (i > 0 && side[i] == side[i-1])
             continue;

           side[i] += matchsticks[idx];

           res |= dfs(matchsticks, idx+1, side, target);

           side[i] -= matchsticks[idx];
        }

        return res;
    }
};