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
     };
    int main(){ 
        Car a("Honda","CiviC x",1000,true); 
        a.request(15);
        a.request(9);
        a.update("Honda","CiviC x",1000,true);
        a.request(5);
        return 0;
    }