class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        int n = arr.size();
        if (n == 1)
          return false;

        //sort(arr.begin(), arr.end());

        unordered_set<int> num_set;
        for (int i = 0; i < arr.size(); i++)
        {
            if (i > 0 && arr[i] % 2 == 0 && num_set.count(arr[i]/2))
              return true;

            if (i > 0 && num_set.count(arr[i]*2))
              return true;

            num_set.insert(arr[i]);
        }

        return false;
    }
};