class Solution {
public:


    vector<int> exclusiveTime(int n, vector<string>& logs) {
         

        vector<int> f_time_cost(n, 0);
        // id stack
        stack<int>  st;

        int pre_timestamp = 0;

         for (string log: logs)
         {
           stringstream ss(log);

           int pre_id = 0;
           int id = 0;
           string status;
           int timestamp = 0;

           int partIdx = 0;
           string part;
           while(getline(ss, part, ':'))
           {
              if (partIdx == 0)
                id = stoi(part);
              else if (partIdx == 1)
                 status = part;
              else if (partIdx == 2)
              {
                   timestamp = stoi(part);
                   if (status == "start")
                   {
                     if (!st.empty())
                     {
                       int time_cost =  timestamp - pre_timestamp;
                       f_time_cost[st.top()] += time_cost;
                     }
                     
                     st.push(id);
                     pre_timestamp = timestamp;
                   }
                   else
                   {
                      int time_cost = timestamp - pre_timestamp + 1;

                      f_time_cost[st.top()] += time_cost;
                      st.pop();

                      pre_timestamp = timestamp + 1;
                   }
              }

              partIdx++;

           }


           pre_id = id;
        }

        return f_time_cost;
    }
};