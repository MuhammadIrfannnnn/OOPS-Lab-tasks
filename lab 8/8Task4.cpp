#include <iostream>
using namespace std;

class Car{
	string model;
	double price;
	public:
		Car(string model,double price):model(model),price(price){}
		friend class Managerinventory;
		friend void compareprice(Car& c1,Car& c2);
};
 void compareprice(Car& c1,Car& c2){
	if(c1.price>c2.price){
		cout<<"car "<<c1.model<<" is more expensive"<<endl;
	}
	else if(c2.price>c1.price) {
		cout<<"car "<<c2.model<< " is more expensive"<<endl;
	}
	else{
	cout<<"car "<<c2.model<< " is equally expensive to car "<<c1.model <<endl;
}
}
class Managerinventory{
	public:
		void modify(double pri,Car& c1){
			c1.price=pri;
		}
		void displaydetails(Car& c1){
			cout<<"Price: "<<c1.price<<endl;
			cout<<"Model: "<<c1.model<<endl;
		}
};
int main(){
	Managerinventory m;
	Car c1("Corolla",500000);
	Car c2("City",750000);
	m.displaydetails(c1);
	m.modify(20000,c1);
	m.displaydetails(c1);
	m.modify(40000,c2);
	m.modify(30000,c1);
	
	compareprice(c1,c2);
	
}