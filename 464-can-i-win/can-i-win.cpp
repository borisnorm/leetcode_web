class Solution {
public:
    
    vector<int> memo;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
          
        int n = maxChoosableInteger;
        vector<int> nums;
        vector<int> visited(n, 0);

        //目标 <= 0，先手不需要选就“已经达到”了（等价于先手立即胜）
        if (desiredTotal <= 0)
          return true;

        long long totalSum = (n * (n + 1))/2;
        if (totalSum < desiredTotal)
          return false;

        for (int i = 1; i <= n; i++)
          nums.push_back(i);
        
        // init:  -1
        // lose:   0
        // win :   1
        memo.resize(1 << n, -1);

        int usedMask = 0;
        return dfs(nums, desiredTotal, usedMask, visited);
    }


    bool dfs(vector<int>& nums, int target, int usedMask, vector<int>& visited)
    {
        int n = nums.size();
        if (target <= 0)
          return false;
        
        if (memo[usedMask] != -1)
          return memo[usedMask];

        for (int i = 0; i < n; i++)
        {
            bool canOppWin = false;

            if (visited[i])
              continue;

            if (nums[i] >= target)
            {
                memo[usedMask] = 1;
                return true;
            }   
            
            visited[i] = 1;
            int nextMask = usedMask | (1 << i);

            canOppWin = dfs(nums, target - nums[i], nextMask, visited);
            visited[i] = 0;

            if (!canOppWin)
            {
               memo[usedMask] = 1;
               return true;
            }
        }
       
        memo[usedMask] = 0;
        return false;
    }
};