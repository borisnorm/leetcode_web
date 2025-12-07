class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> nums1_mp;
        for (auto& num: nums1)
          nums1_mp[num]++;
       
        unordered_map<int, int> nums2_mp;
        for (auto& num: nums2)
          nums2_mp[num]++;

        vector<int> res;
        for (auto& it: nums1_mp)
        {
           int num = it.first;
           if (nums2_mp.count(num))
             res.push_back(num);
        }

        return res;
    }
};