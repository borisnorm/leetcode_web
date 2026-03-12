class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long long const MOD = 1e9 + 7;

        int  n = nums.size();

        unordered_map<long long, long long> l_num2freq;
        l_num2freq[nums[0]]++;

        unordered_map<long long, long long> r_num2freq;
        for (int i = 1; i < n; i++)
          r_num2freq[nums[i]]++;

        long long total_cnt = 0;
        for (int i = 1; i < n-1; i++)
        {
            long long target = nums[i] * 2;

            long long l_cnt = 0;
            if (l_num2freq.count(target))
              l_cnt = l_num2freq[target];
            
            l_num2freq[nums[i]]++;
            
            long long r_cnt = 0;
            r_num2freq[nums[i]]--;
            if (r_num2freq[nums[i]] <= 0)
                r_num2freq.erase(nums[i]);

            if (r_num2freq.count(target))
              r_cnt = r_num2freq[target];
            
            total_cnt += l_cnt * r_cnt;
        }

        return total_cnt % MOD;
    }
};