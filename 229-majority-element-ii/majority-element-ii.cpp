class Solution {
public:
 vector<int> majorityElement(vector<int>& nums) {
      int cand1 = 0;
      int cand2 = 0;
      int cnt1 = 0;
      int cnt2 = 0;

      int n = nums.size();
      vector<int> res;
      for (int num: nums)
      {
        if (cand1 == num)
        {
           cnt1++;
        }
        else if (cand2 == num)
        {
          cnt2++;
        }
        else if (cnt1 == 0)
        {
            cnt1 = 1;
            cand1 = num;
        }
        else if (cnt2 == 0)
        {
            cnt2 = 1;
            cand2 = num;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
      }


      cnt1 = 0;
      cnt2 = 0;
      for (int num: nums)
      {
        if (num == cand1)
          cnt1++;
        else if (num == cand2)
          cnt2++;
      }

      if (cnt1 > n /3)
        res.push_back(cand1);
    
      if (cnt2 > n/3)
        res.push_back(cand2);
    
      return res;
    
      // there are at most 2  which is  > n/3, because  when there are three, there would be   3 * n/3 = n elements;


 }
/*
 vector<int> majorityElement(vector<int>& nums) {
     int n = nums.size();
    vector<int> res;
     if (nums.empty())
       return res;
     sort(nums.begin(), nums.end());


     int cnt = 1;
     for (int i = 1; i < n; i++)
     {
        if (nums[i] == nums[i-1])
        {
            cnt++;
        }
        else
        { 
            if ((cnt) > n/3)
              res.push_back(nums[i-1]);

            cnt = 1;
        }
     }

     //如果最后一段, 一直在进行 cnt++, 那么他就没有机会进行 对 cnt 的总结
     if (cnt > n/3)
       res.push_back(nums[n-1]);

     return res;
 }
 */
/*
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> num2freq;
        unordered_set<int> num_set;
        //vector<int> res;
        int freq = nums.size()/3;
        for (int num: nums)
        {
           num2freq[num]++;
           if (num2freq[num] > freq)
           {
              num_set.insert(num);
           }

        }
        
        vector<int> res(num_set.begin(), num_set.end());
        return res;
    }
*/
};