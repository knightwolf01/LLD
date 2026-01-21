#include <bits/stdc++.h>
using namespace std;

class account{
public:
    virtual void deposite(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class curracc : public account{
private:
    double balance = 0;
public:
    void deposite(double amount){
        balance+=amount;
        cout<<"Deposite "<<amount<<"in current account ,and current balance is "<<balance<<endl;
    }

    void withdraw(double amount){
        if(balance<amount){
            cout<<"The available balance is less than amount"<<endl;
        }
        else{
            balance -= amount;
            cout<<"The withdraw amount is "<<amount<<"and the available balance is "<<balance<<endl;
        }
    }
};
class saving : public account{
private:
    double balance = 0;
public:
    void deposite(double amount){
        balance+=amount;
        cout<<"Deposite "<<amount<<"in saving account ,and saving balance is "<<balance<<endl;
    }

    void withdraw(double amount){
        if(balance<amount){
            cout<<"The available balance is less than amount"<<endl;
        }
        else{
            balance -= amount;
            cout<<"The withdraw amount is "<<amount<<"and the available balance is "<<balance<<endl;
        }
    }
};
class FDacc : public account{
private:
    double balance = 0;
public:
    void deposite(double amount){
        balance+=amount;
        cout<<"Deposite "<<amount<<"in fd account ,and fd balance is "<<balance<<endl;
    }

    void withdraw(double amount){
       throw logic_error("withdraw is not allowed in this account ");
    }
};

class bankClient{
private:
    vector<account*> accounts;
public:
    bankClient(vector<account*> accounts){
        this->accounts = accounts;
    }

    void processTransction(){
        for(auto acc: accounts){
            acc->deposite(1000);

            try{
                acc->withdraw(500);
            }catch(const logic_error& e){
                cout<<"Exception "<<e.what()<<endl;
            }
        }
    }
};

int main(){

    vector<account*> acc;
    acc.push_back(new saving());
    acc.push_back(new curracc());
    acc.push_back(new FDacc());

    bankClient* client = new bankClient(acc);
    client->processTransction();

  return 0;
}
