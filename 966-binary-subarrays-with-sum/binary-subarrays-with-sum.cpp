class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    int atMost(const vector<int>& nums, int S) {
        if (S < 0) return 0;

        int n = (int)nums.size();
        int l = 0;
        int sum = 0;
        int cnt = 0;

        for (int r = 0; r < n; r++) {
            sum += nums[r];

            while (sum > S) {
                sum -= nums[l];
                l++;
            }

            // 以 r 结尾，且和 <= S 的子数组个数
            cnt += (r - l + 1);
        }
        return cnt;
    }
};

/* 
// 超时
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n = nums.size();
        
        int l = 0;
        int r = 0;

        int sum = 0;
        long long cnt = 0;

        
        while(r < n)
        {
           sum += nums[r];
           r++;

           while (sum > goal)
           {
              sum -= nums[l];
              l++;
           }

           while (sum == goal)
           {
              cnt++;
    
              if (nums[l] == 0)
              {
                sum -= nums[l];
                l++;
              }

           }
        } 
        return cnt;
    }
};
*/