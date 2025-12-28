class Solution {
public:
        vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

            int n = arr.size();
            vector<vector<int>> res;
            if (n <= 1)
              return res;

            sort(arr.begin(), arr.end());

            int minDiff = INT_MAX;
            for (int i = 1; i < n; i++)
            {
               int diff = abs(arr[i] - arr[i-1]);

               if (diff < minDiff)
               {
                  res.clear();
                  minDiff = diff;
                  res.push_back({arr[i-1], arr[i]});
               }
               else if (diff == minDiff)
               {
                  res.push_back({arr[i-1], arr[i]});
               }
            }

            return res;
        }

    /*
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        vector<vector<int>> res;

        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int minDiff = INT_MAX;;
        for (int i = 1; i < n; i++)
        {
           int diff = abs(arr[i] - arr[i-1]);
           if (diff < minDiff)
             minDiff = diff; 
        }

        for (int i = 1; i < n; i++)
        {
           int diff = abs(arr[i] - arr[i-1]);
           if (diff == minDiff)
           {
              vector<int> diff_vec;
              //diff_vec.push_back(arr[i-1]);
              //diff_vec.push_back(arr[i]);
             // res.push_back(diff_vec);
              res.push_back({arr[i-1], arr[i]});
           }
        }

        return res;
    }
    */
};