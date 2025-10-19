class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // sliding windows

        int n = arr.size();
        if (n <= 0)
          return {};

        int left = 0;

        // [L, L+ k-1] =  l + k - 1  - l + 1 = k
        // [0, n - 1]
        //   L + k - 1 <= n - 1 
        //  L <= n - k  
        int right = n - k;

        while (left < right)
        {
            int mid = left + (right - left)/2;
            
            // left part      :  right part
            if (x - arr[mid] > arr[mid + k] - x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        vector<int> res(arr.begin() + left, arr.begin() + left +  k);
        return res;
    }
};