class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int maxAltitude = 0;

        int n = gain.size();
        for (int i = 0; i < n; i++)
        {
            altitude += gain[i];
            maxAltitude = max(maxAltitude, altitude);
        }

        return maxAltitude;
    }
};