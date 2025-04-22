#include<iostream>
using namespace std;
class patient{
	protected:
		string name;
		string id;
	public:
		patient(string name,string id):name(name),id(id){
		}
		virtual void displaytreatment()=0;
		virtual void calculatecost()=0;
};
class inpatient: public patient{
	public:
		inpatient(string na,string i):patient(na,i){
		}
		void displaytreatment(){
			cout<<"Inpatient Name: "<<name<<endl<<" id: "<<id<<endl;
		}
		void calculatecost(){
			cout<<"The cost is 20000$"<<endl;
		}
};
class outpatient: public patient{
	public:
		outpatient(string name,string id):patient(name,id){
		}
		void displaytreatment(){
			cout<<"Outpatient Name: "<<name<<endl<<" id: "<<id<<endl;
		}
		void calculatecost(){
			cout<<"The cost is 45000$"<<endl;
		}
		
};
int main(){
	inpatient ip("Irfan","100");
	outpatient op("Huzaifa","101");
	patient* p1=&ip;
	patient* p2=&op;
	p1->displaytreatment();
	p1->calculatecost();
	p2->displaytreatment();
	p2->calculatecost();
	
}
