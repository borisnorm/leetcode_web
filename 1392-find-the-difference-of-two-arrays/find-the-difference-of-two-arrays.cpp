class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> res;

        int m = nums1.size();
        int n = nums2.size();

        unordered_set<int> nums1_set;
        unordered_set<int> nums2_set;

        for (int num : nums1)
          nums1_set.insert(num);
        for (int num : nums2)
          nums2_set.insert(num);

        vector<int> nums1_unique;
        vector<int> nums2_unique;

        for (auto& it : nums1_set)
        {
           int num = it;
           if (!nums2_set.count(num))
             nums1_unique.push_back(num);
        }
       
        for (auto& it : nums2_set)
        {
           int num = it;
           if (!nums1_set.count(num))
             nums2_unique.push_back(num);
        }

        res.push_back(nums1_unique);
        res.push_back(nums2_unique);
        
        return res;

    }
};