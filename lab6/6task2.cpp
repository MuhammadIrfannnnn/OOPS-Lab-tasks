#include<iostream>
using namespace std;

class Vehicle{
    protected:
        string brand;
        int speed;
    public:
        Vehicle(string brand,int speed):brand(brand),speed(speed){}
        void displayDetails(){
            cout<<"--------------------------"<<endl;
            cout<<"Car Brand: " <<brand<<endl;
            cout<<"Car Speed: "<<speed<<endl;
        }

};

class Car:public Vehicle{
    protected:
        int seats;
    public:
        Car(string brand,int speed,int seats):
        Vehicle(brand,speed),seats(seats){}

        void displayDetails(){
            Vehicle::displayDetails();
            cout<<"Car Seats: "<<seats<<endl;
        }
};

class ElectricCar:public Car{
    protected:
        int batteryLife;
    public:
        ElectricCar(string brand,int speed,int seats,int batteryLife):
        Car(brand,speed,seats),batteryLife(batteryLife){}

        void displayDetails(){
            Car::displayDetails();
            cout<<"Car Battery Life: "<<batteryLife<<endl;
        }
};

int main(){
    ElectricCar E1("Tesla",300,4,5000);
    E1.displayDetails();
}