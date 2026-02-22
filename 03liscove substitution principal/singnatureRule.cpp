#include <bits/stdc++.h>
using namespace std;

class parent{
public:
    virtual void print(string msg){
        cout<<"Parent :"<<msg<<endl;
    }
};

class child: public parent{
public:
    void print(string msg) override{
        cout<<"Child: "<<msg<<endl;
    }
};

class Client{
private:
    parent *p;
public:
    Client(parent *p){
        this->p = p;
    }
    void printmsg(){
        p->print("helllo");
    }
};

int main(){
    parent* p = new parent();
    child* c = new child();

    Client* cl = new Client(p);
    cl->printmsg();

  return 0;
}
