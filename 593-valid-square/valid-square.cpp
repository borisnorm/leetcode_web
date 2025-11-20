class Solution {
public:
  
    using T = vector<int>;
    
    long long dist(T& x, T& y)
    {
       long long dist_val = (x[0]-y[0])*(x[0]-y[0]) + (x[1]-y[1])*(x[1]-y[1]);
       return dist_val;
    }

    // 时间 O(1)
    // 空间 O(1)
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // distancance p1 -> p2 == p3 -> p2
        vector<T> points = {p1, p2, p3, p4};

        vector<long long> dist_vec;
        for (int i = 0; i < 4; i++)
          for (int j = i + 1; j < 4; j++)
            dist_vec.push_back(dist(points[i], points[j]));

        sort(dist_vec.begin(), dist_vec.end());

        // 避免出现重合点
        if (dist_vec[0] == 0)
           return false;
        
        if (!(dist_vec[0] == dist_vec[1] && dist_vec[1] == dist_vec[2] && dist_vec[2] == dist_vec[3]))
          return false;

        if (!(dist_vec[4] == dist_vec[5]))
          return false;

        if (!(2* dist_vec[0] == dist_vec[4]))
          return false;

        return true;
        
    }
};