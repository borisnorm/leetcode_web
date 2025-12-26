class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size();
        if (n == 0)
          return {};
        
        vector<int> res;
        map<int, int> arr2pos;
        for (int i = 0; i < n; i++)
           arr2pos[arr[i]] = 0;

        int pos = 1;
        for (auto& it : arr2pos)
        {
           it.second = pos;   // // 第一个(最小)被赋最大rank
           pos++;
        }

        for (int i = 0; i < n; i++)
           res.push_back(arr2pos[arr[i]]);   
    
        return res;
    }
};
/*
class Solution {
public:

    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size();
        if (n == 0)
          return {};
        
        vector<int> res;
        unordered_map<int, int> arr2pos;
        for (int i = 0; i < n; i++)
           arr2pos[arr[i]] = 0;
        
        //vector<int> pos(arr2pos.begin(), arr2pos.end());
        //arr2pos 的迭代器解引用出来的是：
        //unordered_map<int,int>::value_type
        //也就是 pair<const int, int> 
        //但你在构造的是：
        //vector<int>
        // 你等于在说：“把一堆 pair<const int,int> 塞进 int 里”，当然不行。
        // set 却是 可以这样做的

        vector<int> pos;
        for (auto it : arr2pos)
           pos.push_back(it.first);
        
        sort(pos.begin(), pos.end());

        for (int i = 0; i < pos.size(); i++)
          arr2pos[pos[i]] = i + 1;

        for (int i = 0; i < n; i++)
          res.push_back(arr2pos[arr[i]]);   
        
        return res;
    }

    
};

*/

/*
错误

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size();
        if (n == 0)
          return {};
        
        vector<int> res;
        map<int, int> arr2pos;
        for (int i = 0; i < n; i++)
           arr2pos[arr[i]] = 0;

        int pos = arr2pos.size();
        for (auto& it : arr2pos)
        {
           it.second = pos;   // // 第一个(最小)被赋最大rank
           pos--;
        }

        for (int i = 0; i < n; i++)
           res.push_back(arr2pos[arr[i]]);   
    
        return res;
    }
};
*/