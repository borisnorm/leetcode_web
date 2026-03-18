class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        int n = people.size();
        int l = 0;
        int r = n -1;
        int boat = 0;
        while (l <= r)
        {
           if (people[l] + people[r] <= limit)
           {
              l++;
              r--;
           }
           else
           {
              r--;
           }

           boat++;
        }

        return boat;
    }

};