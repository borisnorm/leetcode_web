class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        if (arr.empty())
          return false;
        int n = arr.size();

        sort(arr.begin(), arr.end());

        int pre_k = INT_MAX;
        for (int i = 1; i < n; i++)
        {
          int cur_k = arr[i] - arr[i-1];
            
          if (pre_k != INT_MAX && pre_k != cur_k)
            return false;

          pre_k = cur_k;
        }

        return true;
    }
};