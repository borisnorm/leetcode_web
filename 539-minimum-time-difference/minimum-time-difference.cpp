class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        

        vector<int> time_points;
        for (string time: timePoints)
        {

            string hour_str;
            string min_str;
            stringstream ss(time);

            getline(ss, hour_str, ':');
            getline(ss, min_str, ':');
        
            int min = stoi(hour_str) * 60 + stoi(min_str);

            time_points.push_back(min);
        }

       /*
        using T = pair<int, int>;
        auto cmp = [](const T& a, const T& b){

            if (a.first != b.first)
              return a.first < b.first;
            else
              return a.second < b.second;
        };
        sort(time_points.begin(), time_pionts.end(), cmp);
         */

         sort(time_points.begin(), time_points.end());
        int minDiff = INT_MAX;

        int n = time_points.size();
        for (int i = 0; i < n; i++)
        {
            int diff = 0;
            if (i+1 < n)
              diff = time_points[i+1] - time_points[i];
            else
              diff = time_points[0] + 24 * 60 - time_points[i];

            minDiff = min(minDiff, diff);
        }

        return minDiff;
    }
};