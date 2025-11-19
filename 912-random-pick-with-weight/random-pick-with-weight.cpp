class Solution {

public:
  vector<int> prefixSum;
  int totalSum;

    Solution(vector<int>& w) {
       prefixSum.resize(w.size());
       prefixSum[0] = w[0];
       
       for (int i = 1 ; i < w.size(); i++)
         prefixSum[i] = prefixSum[i-1] + w[i];

      totalSum = prefixSum.back();
    }
    
    int pickIndex() {
        int target = rand() % totalSum + 1;

        int left = 0;
        int right = prefixSum.size();

        while (left < right)
        {
            int mid = left + (right - left)/2;

            if (prefixSum[mid] < target)
              left = mid + 1;
            else
              right = mid;
        }

        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */