class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sum_time = 0; 

        for (int i = 0; i < tickets.size(); i++)
        {
          if (i <= k)
            sum_time += min(tickets[i], tickets[k]);
          else
            sum_time += min(tickets[i], tickets[k]-1);
        } 

        return sum_time;
       
    }
};