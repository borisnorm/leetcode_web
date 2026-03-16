class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // subarray equals to K 

        unordered_map<int, int> prefixSumCnt;
        prefixSumCnt[0] = 1;
        
        int cnt = 0;
        int prefixSum = 0;

        for (int num: nums)
        {
           prefixSum += num;
           
           // prefixSum[j] - prefixSum[i] = k
           // prefixSum[i] = prefix[j] - k;
           // check if previous prefixSum[i] does exist or not
           // 与 two Sum 那个题 类似
           // [i + 1, j] 就是这个解
           //这道题是在做：

          // 当前右端点是 i
          // 找到 mp[cur-k] 个合法左端点
         // 这 mp[cur-k] 个左端点分别对应 mp[cur-k] 个子数组
          // 这些子数组都只是新增答案
          //所以应该加到总数里，而不是和旧答案做组合

           if (prefixSumCnt.count(prefixSum - k))
             cnt += prefixSumCnt[prefixSum - k];

           prefixSumCnt[prefixSum]++;
        }

        return cnt;
    }
};