class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> best(k, -1);

        // 0 <= i <= m
        // 0 <= k -i <= n  -->   i <= k,   k >= k-n;
        int start = max(0, k - n);
        int end   = min(k, m);

        for (int i = start; i <= end; i++)
        {
            auto a = pickMaxSeq(nums1, i);
            auto b = pickMaxSeq(nums2, k-i);

            auto merged = mergeSeq(a, b);
            if (greaterSeq(merged, 0, best, 0))
              best = merged;
        }

        return best;
    }

    vector<int> pickMaxSeq(const vector<int>& nums, int t)
    {
        int drop = (int)nums.size() - t;
        int n = nums.size();
         
        vector<int> st;
        for (int i = 0; i < n; i++){
            
            while(!st.empty() && drop > 0 && nums[i] > st.back()){
                
                drop--;
                st.pop_back();
            }

            st.push_back(nums[i]);
        }

        st.resize(t);
        return st;
    }
   
    bool greaterSeq(const vector<int> & a, int i, const vector<int> & b, int j)
    {
        int m = a.size();
        int n = b.size();

        while (i < m && j < n && a[i] == b[j])
        {
            i++;
            j++;
        }
        
        if (j == n)
          return true;
        
        if (i == m)
          return false;
        
        return a[i] > b[j];
    }

    using T = vector<int>;
    vector<int> mergeSeq(const T& a, const T& b)
    {
        vector<int> res;
        int m = a.size();
        int n = b.size();
        int i = 0;
        int j = 0;

        while (i < m || j < n)
        {
           if (greaterSeq(a, i, b, j))
           {
              res.push_back(a[i]);
              i++;
           }
           else{
              res.push_back(b[j]);
              j++;
           }
        }

        return res; 
    }

};