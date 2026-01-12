class Bank {
public:
    vector<long long> accounts_balance;
    int nAccounts;
    Bank(vector<long long>& balance) {
        int n = balance.size();
        nAccounts = n;
        accounts_balance.resize(n+1, 0);

        for (int i = 1; i <= n; i++)
          accounts_balance[i] = balance[i-1];
    }
    
    bool transfer(int account1, int account2, long long money) {

         if ( account1 > nAccounts || account2 > nAccounts || account1 < 1 || account2 < 1 || accounts_balance[account1] < money )
           return false;
        
         if (account1 == account2)
           return true;
        
         accounts_balance[account1] -= money;
         accounts_balance[account2] += money;

         return true;
    }
    
    bool deposit(int account, long long money) {
         if (account > nAccounts || account < 1)
           return false;
         accounts_balance[account] += money;
         return true;
    }
    
    bool withdraw(int account, long long money) {
         if (account > nAccounts || account < 1  || accounts_balance[account] < money )
           return false;
        accounts_balance[account] -= money;

        return true;
          
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */