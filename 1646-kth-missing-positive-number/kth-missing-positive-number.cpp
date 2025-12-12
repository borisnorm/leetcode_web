class Solution {
public:
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
};