class Solution {
public:

    unordered_map<string, string> parent;
    unordered_map<string, int> rank;

    string find(const string& x)
    {
      if (parent[x] != x)
        parent[x] = find(parent[x]);

       return parent[x];
    }

    void unite(string& x, string& y)
    {
        string rx = find(x);
        string ry = find(y);
        if (rx == ry)
          return ;
        
        if (rank[rx] < rank[ry])
          parent[rx] = ry;
        else if (rank[rx] > rank[ry])
          parent[ry] = rx;
        else
        { 
          parent[ry] = rx;
          rank[rx]++;
        }
    }

    void add(string& x)
    {
       if (!parent.count(x))
       {
          parent[x] = x;
          rank[x] = 0;
       }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        // email -> name , including all email
        // add into parent and 
        unordered_map<string, string> email2name;
        for (auto& account: accounts)
        {
           string name = account[0];
           string firstEmail = account[1];
           email2name[firstEmail] = name;
           
           add(firstEmail);

           for(int i = 2; i < account.size(); i++)
           {
              string email = account[i];
              email2name[email] = name;

              add(email);
              unite(firstEmail, email);
           }
        }

        // go through email to collect and build root->email set
        unordered_map<string, vector<string>> root2email;
        for(auto& [email, name] : email2name)
        {
            string root = find(email);
            root2email[root].push_back(email);
        }

        //build email result
        vector<vector<string>> res;
        for (auto& [root, email_vec]: root2email)
        {
            sort(email_vec.begin(), email_vec.end());

            vector<string> cur_acc;
            string name = email2name[root];
            cur_acc.push_back(name);
            for (string email: email_vec)
              cur_acc.push_back(email);

            res.push_back(cur_acc);
        }

        return res;
    }
};