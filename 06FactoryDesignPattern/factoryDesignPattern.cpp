#include <bits/stdc++.h>
using namespace std;

class Burger{
public:
    virtual void Prepare() = 0;
};

class BasicBurger:public Burger{
public:
    void Prepare()override{
        cout<<"Prepare the Basic Burger "<<endl;
    }
};

class StandardBurger: public Burger{
public:
    void Prepare()override{
        cout<<"Prepare the Standard Burger "<<endl;
    }
};

class PrimeumBurger: public Burger{
public:
    void Prepare()override{
        cout<<"Prepare the Primeum Burger "<<endl;
    }
};

class factory{
public:
    Burger* CreateBurger(string& type){
        if(type == "basic"){
            return new BasicBurger();
        }
        else if(type == "standard"){
            return new StandardBurger();
        }
        else if(type == "primeum"){
            return new PrimeumBurger();
        }
        else{
            cout<<"invalid burger type !!"<<endl;
            return nullptr;
        }
    }
};

int main(){
    string type = "primeum";
    factory* myfactory = new factory();

    Burger* burger = myfactory->CreateBurger(type);

    burger->Prepare();

  return 0;
}
