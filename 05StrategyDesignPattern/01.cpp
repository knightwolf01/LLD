#include <iostream>
using namespace std;

// Base Interfaces with Virtual Destructors
class Talkable {
public:
    virtual void talk() = 0;
    virtual ~Talkable() {} // Vital for cleanup
};

class NormalTalk : public Talkable {
public:
    void talk() override { cout << "Talk normally!!" << endl; }
};

class Walkabel {
public:
    virtual void walk() = 0;
    virtual ~Walkabel() {}
};

class NormalWalk : public Walkabel {
public:
    void walk() override { cout << "Walk Normally !!" << endl; }
};

class Flyable {
public:
    virtual void fly() = 0;
    virtual ~Flyable() {}
};

class NormalFly: public Flyable{
public:
  void fly() override{
    cout<<"Fly normally !!"<<endl;
  }
};

class NoFly : public Flyable {
public:
    void fly() override { cout << "NO Fly !! sorry!!" << endl; }
};

// Base Robot Class
class Robot {
protected: // Protected so children can access if needed
    Talkable *T;
    Walkabel *W;
    Flyable *F;

public:
    Robot(Talkable *T, Walkabel *W, Flyable *F) : T(T), W(W), F(F) {}
    
    virtual ~Robot() { delete T; delete W; delete F; } // Clean up strategy objects

    void walk() { W->walk(); }
    void talk() { T->talk(); }
    void fly()  { F->fly(); }

    virtual void Projection() = 0;
};

// Use PUBLIC inheritance
class CompanionRobot : public Robot {
public:
    // Ensure the order matches the constructor: Talk, Walk, Fly
    CompanionRobot(Talkable* T, Walkabel* W, Flyable* F) : Robot(T, W, F) {}

    void Projection() override {
        cout << "This is your companion Robot !!!" << endl;
    }
};

class WorkerRobot: public Robot{
public:
  WorkerRobot(Talkable* T, Walkabel* W, Flyable* F): Robot(T,W,F){}
  void Projection() override{
    cout<<"I am your working robot !!!"<<endl;
  }
};

int main() {
    // Corrected Argument Order: Talkable first, then Walkable, then Flyable
    Robot* myRobot = new CompanionRobot(new NormalTalk(), new NormalWalk(), new NoFly());

    myRobot->Projection();
    myRobot->talk();
    myRobot->fly();
    myRobot->walk();

    cout<<"________________"<<endl;

    Robot* WRobot = new WorkerRobot(new NormalTalk(),new NormalWalk(), new NormalFly());
    WRobot->Projection();
    WRobot->fly();
    WRobot->walk();
    WRobot->talk();
    
    delete myRobot; // Now safe due to virtual destructors
    delete WRobot;
    return 0;
}