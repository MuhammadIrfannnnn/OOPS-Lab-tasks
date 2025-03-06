#include<iostream>
using namespace std;

class Device{
    protected:
        int DeviceId;
        bool status;
    public:
        Device(int DeviceId,bool status):DeviceId(DeviceId),status(status){}
        void displayDetails(){
            cout<<"--------------------------"<<endl;
            cout<<" Device ID: " <<DeviceId<<endl;
            cout<<"Status: "<<status<<endl;
        }

};

class SmartPhone:virtual public Device{
    protected:
        float screensize;
    public:
        SmartPhone(int DeviceId,bool status,float screensize):
        Device(DeviceId,status),screensize(screensize){}

        void displayDetails(){
            Device::displayDetails();
            cout<<"Screen Size: "<<screensize<<endl;
        }
};

class SmartWatch:virtual public Device{
    protected:
        bool heartratemonitor;
    public:
    SmartWatch(int DeviceId,bool status,bool heartratemonitor):
    Device(DeviceId,status),heartratemonitor(heartratemonitor){}

        void displayDetails(){
            Device::displayDetails();
            cout<<"Heart Rate Monitor: "<<heartratemonitor<<endl;
        }
};

class smartWearable:public SmartPhone,public SmartWatch{
    protected:
        int stepcounter;
    public:
            smartWearable(int DeviceId,bool status,float screensize,bool heartratemonitor,int stepcounter):
            Device(DeviceId,status),SmartPhone(DeviceId,status,screensize),SmartWatch(DeviceId,status,heartratemonitor),stepcounter(stepcounter){}
            void displayDetails(){
               Device::displayDetails();
               cout<<"Screen Size: "<<screensize<<endl;
               cout<<"Heart Rate Monitor: "<<heartratemonitor<<endl;
               cout<<"Step Counter: "<<stepcounter<<endl;
            }
        };

int main() {

            smartWearable sw(101, true, 6.5, true, 5000);
        
            sw.displayDetails();
        
            return 0;
 }