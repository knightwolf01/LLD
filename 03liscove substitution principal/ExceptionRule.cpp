#include <bits/stdc++.h>
using namespace std;

class parent{
public:
    virtual void getval() noexcept(false){
        throw logic_error("parent error");
    } 
};

class child: public parent{
public:
    void getval() noexcept(false){
        // throw range_error("child error "); //this is wrong because child should throw error of same as parent or narrow version of parent 
        throw out_of_range("child's error !!");
    }
};

class client {
private:
    parent* p;
public:
    client(parent* p){
        this->p = p;
    }
    void takeval(){
        try{
            p->getval();
        }
        catch(const logic_error& e){
            cout<<"logic error exception occured " << e.what() << '\n';
        }
    }
};

int main(){
    parent* p = new parent();
    child* c = new child();

    client* cl = new client(c);

    cl->takeval();

  return 0;
}
