#include<iostream>
using namespace std;
class shipment{
protected:
	string trackingnumber;
	double weight;
	public:
		shipment(string number,double weight):trackingnumber(number),weight(weight){
		}
		void virtual estimatedeliverlytime()=0;
		void virtual showdetails()=0;
};
class airfreight :public shipment{
public:
	airfreight(string num,double kg):shipment(num,kg){
	}
	void estimatedeliverlytime(){
		cout<<"Estimating air deliverly time"<<endl;
	}
	void showdetails(){
		cout<<"Air tracking number : "<<trackingnumber<<endl<<"weight: "<<weight<<endl;
	}
		
};
class groundshipment :public shipment{
public:
	groundshipment(string num,double kg):shipment(num,kg){
	}
	void estimatedeliverlytime(){
		cout<<"Estimating ground deliverly time"<<endl;
	}
	void showdetails(){
		cout<<"Ground tracking number : "<<trackingnumber<<endl<<"weight: "<<weight<<endl;
	}
};
int main(){
groundshipment g("100",80);
airfreight a("101",150);
shipment* s1=&g;
shipment* s2=&a;
s1->estimatedeliverlytime();
s1->showdetails();
s2->estimatedeliverlytime();
s2->showdetails();

}

