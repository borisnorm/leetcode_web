class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //  pos      --        target
        //  speed    
        //  time= (target−position[i])​ / speed[i]
        
        //----------------------------->  
        //  p1,    p2,      p3

        // 1. form cars [pos, time] status vector 
        // 2. sort based on dist to destination from nearest to farthest  
        //    p3.val > p2.val > p1.val
        //    p3距离 destination 更近,
        // 3. put cars into monolithic inceasing stack
        //    p2.time() >= p3.time()  没问题
        //    cur[i] < st.top() 单调递增  

        // pos, time to destination
        int n = position.size();
        vector<pair<int, double>> cars(n);

        for (int i = 0; i < n; i++)
        {
           //除法优先级比减法高  
           cars[i] = {position[i], (double)(target-position[i])/speed[i]};
        }
       
        using T = pair<int, double>;
        sort(cars.begin(), cars.end(), [](const T& a, const T& b){
             return a.first > b.first;
        });

        stack<double> st;
        for(int i = 0; i < n; i++)
        {
           auto& [pos, t] = cars[i];
           //t == st.top() 时表示同时到达，应该合并
           if (!st.empty() && t <= st.top())
           {
              continue;  
           }

           st.push(t);
        }

        return st.size();
    }
};