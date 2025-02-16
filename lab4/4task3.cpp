#include<iostream> 
using namespace std; 
class Car{ 
    private: 
        string brand; 
        string model;
        float price;
        bool avaibility;
     public: 
        Car(){ 
            brand="unknown"; 
            model="Genric"; 
            price=0.0; 
            avaibility=true; 
        } 
        Car(string b,string m,float p,bool a){
            brand=b;
            model=m;
            price=p;
            avaibility=a;
        }
        Car(Car &obj){
            brand=obj.brand;
            model=obj.model;
            price=obj.price;
            avaibility=obj.avaibility;
        }
        void request(int days){ 
            cout<<"Request for Rent"<<endl;
            cout<<"-----------------"<<endl;
            if(avaibility){ 
                if(days>=5 && days<10){
                    float discount=price*0.05;
                    cout<<"Your request accept"<<endl;
                    cout<<"Discounted price is PKR "<<price-discount<<endl;
                    avaibility=false;
                }
              else if(days>=10){
                    float discount=price*0.1;
                    cout<<"Your request accept"<<endl;
                    cout<<"Discounted price is PKR"<<price-discount<<endl;
                    avaibility=false;
                }
              else{
                cout<<"Your request accept"<<endl;
                avaibility=false;
              }  
             } 
             else{
                 cout<<"Not available"<<endl;
                } 
            } 
        void update(string b,string m,float p,bool a){
             brand=b;
             model=m;
             price=p;
             avaibility=a;
          } 

        void display(){
            cout<<"Brand: "<<brand<<" || Model: "<<model<<" || Rental Price: "<<price<<" || Avaibility: "<<avaibility<<endl;
        }
        ~Car(){
            cout<<"destructor for "<<brand<<" "<<model<<endl;
        }
     };
    int main(){ 
        Car a("Honda","CiviC x",1000,true); 
        cout<<"Orginal Car"<<endl;
        a.display();
        Car b(a);
        cout<<"Copied Car"<<endl;
        b.display();
        a.update("Toyota","Corrola",5000,false);
        cout<<"Orginal Car after update"<<endl;
        a.display();
        cout<<"Copied Car after original update"<<endl;
        b.display();
        return 0;
    }