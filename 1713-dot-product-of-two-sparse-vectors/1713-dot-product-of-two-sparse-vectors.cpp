class SparseVector {
public:
    vector<pair<int, int>> data;
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0){
               data.push_back({i, nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        
        int m = data.size();
        int n = vec.data.size();

        int i = 0;
        int j = 0;
        
        long long res = 0;
        while(i < m && j < n)
        {
           if (data[i].first == vec.data[j].first)
           {
                res += (data[i].second) * (vec.data[j].second);
                i++;
                j++;
           }
           else if (data[i].first < vec.data[j].first)
           {
              i++;
           }
           else
           {
              j++;
           }
        }

        return (int)res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);