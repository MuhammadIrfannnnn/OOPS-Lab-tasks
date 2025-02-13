#include<iostream>
using namespace std;

class Car{
    private:
        string brand;
        int model;
        double fuelcapacity;
        double currentfuellevel;
    public:
        void setdetails(string b,int m,double f,double c){
            brand=b;
            model=m;
            fuelcapacity=f;
            currentfuellevel=c;
        }
        void drivecar(double dist){
            double fueluse=dist*0.5;
            if(fueluse>currentfuellevel){
                cout<<"Fuel end"<<endl;
            }
            else{
                currentfuellevel-=fueluse;
                cout<<"Fuel left: "<<currentfuellevel<<"L"<<endl;
            }
            if(currentfuellevel<10){
                cout<<"Low fuel just "<<currentfuellevel<<"L left"<<endl;
            }
        }
    void refuel(double qty){
        if(qty+currentfuellevel>fuelcapacity){
            currentfuellevel=fuelcapacity;
            cout<<"Full Tank"<<endl;
        }
        else{
            currentfuellevel+=qty;
            cout<<"Now fuel is "<<currentfuellevel<<"L "<<endl;
        }
    }
    void fuelstatus(){
        cout<<"Brand: "<<brand<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Fuel Capacity: "<<fuelcapacity<<endl;
        cout<<"Current Fuel Level: "<<currentfuellevel<<"L "<<endl;
    }
};

int main(){
    Car zoya;
    zoya.setdetails("Toyota",2022,100,30);
    zoya.drivecar(50);
    zoya.refuel(30);
    zoya.fuelstatus();

    return 0;
}