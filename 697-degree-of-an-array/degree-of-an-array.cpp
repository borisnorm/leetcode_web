class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
         if (nums.empty())
           return 0;
        
         int n = nums.size();
         unordered_map<int, int> num2freq;
         unordered_map<int, int> first, last;
         int maxFreq = 0;
         for (int i = 0; i < n; i++)
         {
            int num = nums[i];

            if (!first.count(num))
              first[num] = i;
            last[num] = i;
            num2freq[num]++;
            maxFreq = max(maxFreq, num2freq[num]);
         }
         
         int minLen = n;
         for(auto num2freq_pair: num2freq)
         {
            if (num2freq_pair.second == maxFreq)
            {
              int num = num2freq_pair.first;
              int len = last[num] - first[num] + 1;
              minLen = min(minLen, len);
            } 
         }
           
        return minLen;
         
    }
};