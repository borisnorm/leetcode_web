class FindSumPairs {
public:
    vector<int> n1, n2;
    unordered_map<int, int> nums2_freq;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (int num: nums2)
          nums2_freq[num]++;
    }
    
    void add(int index, int val) {
       int old_val = n2[index];
       nums2_freq[old_val]--;

       n2[index] += val;
       int new_val = n2[index];
       nums2_freq[new_val]++; 
    }
    
    int count(int tot) {
       int cnt = 0;
       for (int x: n1)
       {
         int target = tot  - x;
         if (nums2_freq.count(target))
         {
            int nValidTarget = nums2_freq[target];
            cnt += nValidTarget;
         }
       }

       return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */