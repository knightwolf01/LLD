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

class BasicWheatBurger: public Burger{
public:
    void Prepare()override{
        cout<<"Prepare BasicWheatBurger  "<<endl;
    }
};

class StandardWheatBurger: public Burger{
public:
    void Prepare()override{
        cout<<"Prepare StandardWheatBurger "<<endl;
    }
};

class PrimeumWheatBurger: public Burger{
public:
    void Prepare()override{
        cout<<"Prepare PrimeumWheatBurger "<<endl;
    }
};

class BurgerFactory{
public:
    virtual Burger* CreateBurger(string& type) = 0;
};

class kingBurger: public BurgerFactory{
public:
    Burger* CreateBurger(string& type)override{
        if(type == "basic"){
            return new BasicWheatBurger();
        }
        else if(type == "standard"){
            return new StandardWheatBurger();
        }
        else if(type == "primeum"){
            return new PrimeumWheatBurger();
        }
        else{
            cout<<"invalid burger type !!"<<endl;
            return nullptr;
        }
    }
};

class singBurger: public BurgerFactory{
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
    string type = "basic";

    BurgerFactory* factory = new kingBurger();
    
    Burger* burger = factory->CreateBurger(type);

    burger->Prepare();

  return 0;
}
