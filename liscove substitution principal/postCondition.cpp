#include <bits/stdc++.h>
using namespace std;

class car{
protected:
    int speed;
public:
    car(){
        speed = 0;
    }
    void accelerate(){
        speed+=10;
        cout<<"speed increased by 10 and the current spped is "<<speed<<endl;
    }
    virtual void brake(){
        if(speed <= 0) cout<<"car is already in rest "<<endl;
        cout<<"Brake is applied "<<endl;
        speed-=10;
    }
};

class ElectricCar: public car{
protected:
    int charge;
public:
    ElectricCar() : car(){
        charge = 0;
    }

    void brake(){
        if(speed <= 0) cout<<"car is already in rest "<<endl;
        cout<<"Brake is applied "<<endl;
        speed-=10;
        charge+=10;
        cout<<"The current charge is "<<charge<<endl;
    }
};

int main(){
    // car* c = new car();
    ElectricCar* ec = new ElectricCar();
    ec->accelerate();
    ec->accelerate();

    ec->brake();


  return 0;
}
