
class Solution
{
public:
  int countValidSelections(vector<int>& nums)
  {
    int total = 0;
    for (int x : nums)
       total += x;
    
    int res = 0;
    int prefix = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
          prefix += nums[i];
          continue;
        }
        
        int L = prefix;
        int R = total - prefix; // nums[i]=0 不影响
        
        if (L == R)       res += 2; // 两个方向都行
        else if (abs(L-R) == 1) res += 1; // 只有一个方向行
    }
  
    return res;
  }
};