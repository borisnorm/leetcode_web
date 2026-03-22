
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt = 0;
        unordered_map<int, int> freq;

        for (int num: nums)
        {
           //当前这个num 之前出现过 freq[num]次, 每次都能跟 当前这个位置配对, 
           // 之前的 每一个 num (num 出现的次数), 与 cur 的 num 都能1-1 配对  
           cnt += freq[num];
           freq[num]++;
        }

        return cnt;
    }
};
/*
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i + 1 < n; i++)
        {
           for (int j = i + 1; j < n; j++)
           {
              if (nums[i] == nums[j])
                cnt++;
           }
        }

        return cnt;
    }
};
*/