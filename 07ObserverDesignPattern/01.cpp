#include <bits/stdc++.h>
using namespace std;

class Isubscriber{
public:
    virtual void update() = 0;
};

class Ichannel{
public:
    virtual void subscribe(Isubscriber& subscriber) = 0;
    virtual void unsubscribe(Isubscriber& subscriber) = 0;
    virtual void notify() = 0;
};

class channel: public Ichannel{
private:
    vector<Isubscriber*> subscribers;
    string name, latestVideo;
public:
    channel(const string& name){
        this->name=name;
    }
    void subscribe(Isubscriber& subscriber) override{
        if(find(subscribers.begin(),subscribers.end(),&subscriber)==subscribers.end()){
            subscribers.push_back(&subscriber);
        }
    }
    void unsubscribe(Isubscriber& subscriber) override{
        auto it = find(subscribers.begin(),subscribers.end(),&subscriber);
        if(it != subscribers.end()){
            subscribers.erase(it);
        }
    }

    void notify() override{
        for(auto it:subscribers){
            it->update();
        }
    }

    void uploadVideo(const string& title){
        latestVideo = title;
        cout<<"\n checkout our new video: "+ latestVideo <<endl;
        notify();
    }

    string getvideo(){
        return "\nCheckout our new video "+ latestVideo+"\n";
    }

};

class Subscriber:public Isubscriber{
private:
    string name;
    channel* chanl;
public:
    Subscriber(const string& name, channel* chanl){
        this->name = name;
        this->chanl = chanl;
    }

    void update() override{
        cout<<"Hey "<<name<<","<<this->chanl->getvideo()<<endl;
    }
};

int main(){

    channel* chnl = new channel("sanu kumar singh");
    
    Subscriber* subs1 = new Subscriber("Varun",chnl);
    Subscriber* subs2 = new Subscriber("Arun",chnl);

    chnl->subscribe(*subs1);
    chnl->subscribe(*subs2);

    chnl->uploadVideo("make ats friendly resume ");

    chnl->unsubscribe(*subs1);

    chnl->uploadVideo("don't make ats friendly resume");

  return 0;
}
