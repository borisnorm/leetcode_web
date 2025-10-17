class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        if (temperatures.empty())
          return {};

        int n = temperatures.size();
        vector<int> res(n, 0);
 
        stack<int> s;
        for (int i = n-1; i >= 0; i--)
        {
           while(!s.empty() && temperatures[i] >= temperatures[s.top()] )
             s.pop();
           
           res[i] = s.empty() ? 0 : (s.top()-i);

           s.push(i);
        }
        
        return res;
    }
};