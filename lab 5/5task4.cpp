#include<iostream>
using namespace std;

class Firealarm{
    private:
        string level;
    public:
        Firealarm(string level){
            this->level=level;
        }

    string getlevel(){
        return level;
    }
    ~Firealarm(){
        cout<<endl<<"Fire Alarm destroy"<<endl;
        
     }

};

class Smarthome{
    private:
        int id;
        string owner;
        Firealarm Alarm;
    public:
    Smarthome(int id, string owner, string level) : id(id), owner(owner), Alarm(level) {} 


        void display(){
            cout<<"--------------------------"<<endl;
            cout<<"ID: "<<id<<endl;
            cout<<"Owner Name: "<<owner<<endl;
            cout<<"Alarm system: "<<Alarm.getlevel()<<endl;
        }

        ~Smarthome(){
           cout<<endl<<"Smart home destroy"<<endl;
           
        }

};

int main(){
    Smarthome s1(100,"Irfan","High");
    s1.display();
}
