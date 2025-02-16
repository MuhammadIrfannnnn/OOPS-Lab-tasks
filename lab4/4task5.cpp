#include <iostream>
using namespace std;

class Car {
private:
    int carID; 
    string brand;
    string model;
    float price;
    bool availability;
    float *totalRevenue; 

public:
    Car(int id, string b, string m, float p, bool a) 
        : carID(id), brand(b), model(m), price(p), availability(a), totalRevenue(new float(0.0))
		 {}

    void request(int days) {
        cout << "Request for Rent - Car ID: " << carID << endl;
        if (availability) {
            float finalPrice = price * days;
            if (days >= 5 && days < 10) {
                float discount = price * 0.05;
                finalPrice -= discount * days;
            } 
            else if (days >= 10) {
                float discount = price * 0.1;
                finalPrice -= discount * days;
            }
            cout << "Your request is accepted!\n";
            cout << "Total Rental Cost: PKR " << finalPrice << endl;
            *totalRevenue += finalPrice; 
            availability = false;
        } else {
            cout << "Car is not available for rent." << endl;
        }
    }

    void update(int id,string b, string m, float p, bool a) {
        brand = b;
        model = m;
        price = p;
        availability = a;
        carID=id;
    }

    void display() const {
        cout << "Car ID: " << carID << " | Brand: " << brand 
             << " | Model: " << model << " | Price: PKR " << price 
             << " | Availability: " << availability
             << " | Total Revenue: PKR " << *totalRevenue << endl;
        cout<<"------------------------------------------------------------"<<endl;
    }

    ~Car() {
        cout << "Destructor for car id " << carID <<endl;
        delete totalRevenue;
    }
};

int main() {
    Car car1(101, "Honda", "Civic X", 1000, true);
    Car car2(102, "Toyota", "Corolla", 1500, true);
    Car car3(103, "Suzuki", "Swift", 1200, false);

    cout << "--- Initial Car Details ---"<<endl;
    car1.display();
    car2.display();
    car3.display();
    cout<<"Renting a Car"<<endl;
    car1.request(7); 
    car2.request(15);
    cout<<"Updated Car Details"<<endl;
    car1.display();
    car2.display();
    cout<<"Updating Car Details"<<endl;
    car2.update(104,"Ford","Focus",1800,true);
    car2.display();

    return 0;
}
