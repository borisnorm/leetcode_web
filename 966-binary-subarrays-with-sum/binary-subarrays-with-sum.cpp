
/*
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      
        int sum = 0;
        unordered_map<long long, int> sum2cnt;
        int cnt = 0;

        // prefixSum 空集 有解
        sum2cnt[0] = 1;

        for (int num: nums)
        {
           sum += num;
           if (sum2cnt.count(sum-goal))
              cnt += sum2cnt[sum-goal];

           sum2cnt[sum]++;
        }

        return cnt;
    }
};
*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // prefixSum <= gobal
        return numPrefixSum(nums, goal) - numPrefixSum(nums, goal-1);
    }

    int numPrefixSum(vector<int>& nums, int goal)
    {
        if (goal < 0)
          return 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        int cnt = 0;
        long long sum = 0;
        while (r < n)
        {
            sum += nums[r];
            r++;

            while (sum > goal)
            {
               sum -= nums[l];
               l++;
            }

            cnt += r-l;
        }
        return cnt;
    }
};

/*
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
*/