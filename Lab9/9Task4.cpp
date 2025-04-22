#include<iostream>
using namespace std;
class weathersensor{
	public:
		void virtual readdata(double value)=0;
		void virtual displayreport()=0;
		
};
class thermometer :public weathersensor{
	double temp;
	public:
		thermometer(){
			temp=0;
		}
		void readdata(double value){
			temp=value;
			cout<<"Reading data of thermometer"<<endl;
		}
		void displayreport(){
			cout<<"Temperature is " << temp << "C"<<endl;
		}
		
};
class barometer :public weathersensor{
	double pressure;
		public:
			barometer(){
				pressure=0;
			}
		void readdata(double value){
			pressure=value;
			cout<<"Reading data of barometer"<<endl;
		}
		void displayreport(){
			cout<<"Pressure is "<<pressure <<  " pascals"<<endl;
		}
};
int main(){
	barometer b;
	thermometer t;
	weathersensor * w1=&b;
	weathersensor * w2=&t;
	w1->readdata(450);
	w1->displayreport();
	w2->readdata(105);
	w2->displayreport();
}
