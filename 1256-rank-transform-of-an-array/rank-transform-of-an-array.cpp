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

/*
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
           it.second = pos;
           pos--;
        }

        for (int i = 0; i < n; i++)
           res.push_back(arr2pos[arr[i]]);   
    
        return res;
    }
};
*/