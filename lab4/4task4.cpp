#include<iostream> 
using namespace std; 
class Car{ 
    private: 
        string brand; 
        string model;
        float price;
        bool avaibility;
        float* revenue;
     public: 
        Car(){ 
            brand="unknown"; 
            model="Genric"; 
            price=0.0; 
            avaibility=true; 
            revenue=new float(0.0);
        } 
        Car(string b,string m,float p,bool a){
            brand=b;
            model=m;
            price=p;
            avaibility=a;
            revenue=new float(0.0);
        }
        Car(Car &obj){
            brand=obj.brand;
            model=obj.model;
            price=obj.price;
            avaibility=obj.avaibility;
            revenue=obj.revenue;
        }
        void request(int days) {
		        cout << "Request for Rent"<< endl;
		        if (avaibility) {
		            float finalPrice = price * days;
		            if (days >= 5 && days < 10) {
		                float discount = price * 0.05;
		                finalPrice -= discount * days;
		            } 
		            else if (days >= 10) {
		                float discount = price * 0.1;
		                finalPrice -= discount * days;
		            }
		            cout << "Your request is accepted!"<<endl;
		            cout << "Total Rental Cost: PKR " << finalPrice << endl;
		           *revenue += finalPrice; 
		            avaibility = false;
		        } else {
		            cout << "Car is not available for rent." << endl;
		        }
		    }
        void update(string b,string m,float p,bool a){
            cout<<"After Updation"<<endl;
             brand=b;
             model=m;
             price=p;
             avaibility=a;
          } 

        void display(){
            cout<<"Brand: "<<brand<<" || Model: "<<model<<" || Rental Price: "<<price<<" || Avaibility: "<<avaibility<<" || Revenue: "<<*revenue<<endl;
            cout<<"------------------------------------------------------------------------------------------"<<endl;
        }
        ~Car(){
            cout<<"destructor for "<<brand<<" "<<model<<endl;
            delete revenue;
        }
     };
    int main(){ 
        Car a("Honda", "Civic X", 1000, true); 
    cout << "Original Car (before rental):" << endl;
    a.display();
    cout <<"Renting for 7 days:" << endl;
    a.request(7);
    a.display();  
    cout<<"rent again for 5 days:" << endl;
    a.request(5);
    a.display();
    a.update("Honda", "Civic X", 1000, true);
    a.display();
    cout<<"rent again for 2 days:" << endl;
    a.request(2);
    a.display();
    
        return 0;
    }
