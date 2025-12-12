class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int n = (int)arr.size();

        auto missing = [&](int i){
            return arr[i] - (i+1);
        };
        
        if (missing(n-1) < k)
          return arr[n-1] + (k - missing(n-1));

        int l = 0;
        int r = n - 1;

        while (l < r)
        {
            int mid = l + (r-l)/2;
            if (missing(mid) >= k)
              r = mid;
            else
              l = mid + 1;
        }
        // arr[l-1] < 第 k 个 missing 数 ≤ arr[l]
        // arr[l-1] < x ≤ arr[l]
        // arr[0] ....... arr[l-1] 共 l 个
        // x(不缺失时候应该出现的数字数量) - l (缺失时 出现的数字数量) = k 
        return l + k;

    }

/*
        int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        
        unordered_set<int> arr_set;
        for (auto num: arr)
          arr_set.insert(num);

        vector<int> missing_set;
        for (int i = 1; i <= arr[n-1]; i++)
        {
           if (!arr_set.count(i))
             missing_set.push_back(i);
        }

        int missing_set_size = missing_set.size();

        if (k <= missing_set_size)
          return missing_set[k-1];
        else
        {
           int offset = k - missing_set_size;
           return arr[n-1] + offset;
        }
    }
    */
};