class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // [low] [high]
        //  偶数个元素 median (low.rbegin() + high.begin()) / 2
        //  奇数个元素 median  low.rbegin()
        //  low.size()= high.size() + 1
        multiset<int> low;
        multiset<int> high;
        vector<double> res;

        auto rebalance = [&](){
           //if (low.size() < high.size() + 1)
           // 等价于 low.size() <= high.size()  //偶数 case 是成立的
           // 我们只是需要 low.size() < high.size();
           
           if (low.size() > high.size() + 1)
           {
              high.insert(*low.rbegin());
              // erase 只接受 正向 迭代器
              low.erase(prev(low.end()));
           }
           else if (low.size() < high.size())
           {
              low.insert(*high.begin());
              high.erase(high.begin());
           }
        };

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
           // step 1: increase new element
          if (low.empty() || nums[i] <= *low.rbegin())
            low.insert(nums[i]);
          else
            high.insert(nums[i]);
          
          rebalance();

           // step 2: record result
           if (i >= k-1)
           {
              if (k & 0x1)
                res.push_back((double)*low.rbegin());
              else
                res.push_back(((double)*low.rbegin() + (double)*high.begin())/2);
              
              int leftmost = nums[i-k+1];

              if (low.count(leftmost))
                low.erase(low.find(leftmost));
              else
                high.erase(high.find(leftmost));

              rebalance();
           }
        }
        return res;
    }
};