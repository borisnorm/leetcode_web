class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res;

        unordered_map<int, int> nums1_freq;
        for (int num: nums1)
          nums1_freq[num]++;
        
        for (int num: nums2)
        {
           if (nums1_freq[num] > 0)
           {
              res.push_back(num);
              nums1_freq[num]--;
           }
        }

        return res;
    }
};

/*
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums1_mp;
        for (auto& num: nums1)
          nums1_mp[num]++;
       
        unordered_map<int, int> nums2_mp;
        for (auto& num: nums2)
          nums2_mp[num]++;
        
        vector<int> res;
        for (auto& p: nums1_mp)
        {
           int num = p.first;
           if (nums2_mp.count(num))
           {
             for (int i = 0; i < min(p.second, nums2_mp[num]); i++)
               res.push_back(num);
           }
        }

        return res;
    }
};

*/