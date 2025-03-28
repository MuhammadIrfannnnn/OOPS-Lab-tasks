#include<iostream>
using namespace std;

class Device{
    protected:
        int id;
        string name;
        bool status;
        string location;
    public:
        Device(int id,string name,string location):
        id(id),name(name),status(false),location(location){}

       virtual void turnon(){
            status =true;
        }
       virtual void turnoff(){
            status=false;
        }
        virtual bool getstatus(){
            cout<<"Staus is: "<<(status?"ON":"OFF")<<endl;
            return status;
        }
        virtual void displayinfo(){
            cout<<"ID: "<<id<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Status: "<<status<<endl;
            cout<<"location: "<<location<<endl;
        }

};

class Light:public Device{
    private:
        int brightnesslevel;
        string colormode;
    public:
        Light(int id,string name,string location,int brightnesslevel,string colormode):
        Device(id,name,location),brightnesslevel(brightnesslevel),colormode(colormode){}

        void displayinfo(){
            cout<<"ID: "<<id<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Status: "<<status<<endl;
            cout<<"location: "<<location<<endl;
            cout<<"Brightness Level: "<<brightnesslevel<<endl;
            cout<<"Color Mode: "<<colormode<<endl;
        }

};

class Thermostat:public Device{
    private:
    float temperature;
    string mode;
    float targetTemperature;

    public:
    Thermostat(int id, string name, string location, float temp, string m, float targetTemp)
        : Device(id, name, location), temperature(temp), mode(m), targetTemperature(targetTemp) {}

    bool getstatus()  {
        cout << name << " is set to " << mode 
             << " mode with current temperature " << temperature 
             << "°C and target temperature " << targetTemperature << "°C."<<endl;
    }

};

class SecurityCamera:public Device{
    private:
        double resolution;
        bool recordingstatus;
        bool nightvision;
    public:
        SecurityCamera(int id,string name,string location,double resolution,bool nightvision):
        Device(id,name,location),resolution(resolution),recordingstatus(false),nightvision(nightvision){}

        void turnon(){
            status=true;
            recordingstatus=true;
            cout<<name<<" Starts Recording"<<endl;
        }

};

class SmartPlug:public Device{
    private:
        float powerConsumption;
        int timerSetting;
    public:
        SmartPlug(int id,string name,string location,float powerConsumption,int timerSetting):
        Device(id,name,location),powerConsumption(powerConsumption),timerSetting(timerSetting){}

        void turnoff(){
            status=false;
            cout<<name<<"Log power Usage "<<powerConsumption<<" km/h";
        }
};

int main(){
    Device* ptr1;
    Light L(100,"Light","ABC",100,"Black");
    ptr1=&L;
    ptr1->displayinfo();
    Thermostat T(101,"Thermostat","AAA",78.5,"Heat",100);
    ptr1=&T;
    ptr1->getstatus();
    SecurityCamera S(102,"Camera","BBB",720,true);
    ptr1=&S;
    ptr1->turnon();
    SmartPlug P(103,"Plug","CCC",500,60);
    ptr1=&P;
    ptr1->turnoff();

    return 0;


}
