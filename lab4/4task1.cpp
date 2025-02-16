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
        void request(){ 
            if(avaibility){ 
                cout<<"Your request accept"<<endl;
                avaibility=false;
             } 
             else{
                 cout<<"Not available"; 
                } 
            } 
        void update(string b,string m,float p,bool a){
             brand=b;
             model=m;
             price==p;
             avaibility=a;
          } 
     };
    int main(){ 
        Car a; 
        a.update("toyoyta","model",100,true); 
        a.request();
        a.request();
        
        return 0;
    }