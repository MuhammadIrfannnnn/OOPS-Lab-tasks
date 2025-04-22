#include<iostream>
using namespace std;
class menuitem{
	protected:
		string dishname;
		double price;
	public:
		menuitem(string name,double price):dishname(name),price(price){
		}
		virtual void showdetails()=0;
		virtual void prepare()=0;
};
class appetizer: public menuitem{
	public:
		appetizer(string name,double price):menuitem(name,price){
		}
		void showdetails(){
			cout<<"appetizer dishname: "<<dishname<<endl<<"price: "<<price<<endl;
		}
		void prepare(){
			cout<<"appetizer "<<dishname<<" is to prepared"<<endl;
		}
};
class maincourse: public menuitem{
	public:
		maincourse(string name,double price):menuitem(name,price){
		}
		void showdetails(){
			cout<<"main dishname: "<<dishname<<endl<<"price: "<<price<<endl;
		}
		void prepare(){
			cout<<"main "<<dishname<<" is to prepared"<<endl;
		}
		
};
int main(){
appetizer ap("Cheese Balls",1000);
maincourse ma("Pasta",1800);

menuitem* d1=&ap;
menuitem* d2=&ma;
d1->showdetails();
d1->prepare();
d2->showdetails();
d2->prepare();

return 0;

}

