#include<iostream>
using namespace std;

class Apartment{
    string id;
    string address;
    string* ownerName;
    public:
    Apartment(string i, string a, string o){
        id = i;
        address = a;
        ownerName = new string(o);
    }
    Apartment(Apartment &a){
        id = a.id;
        address = a.address;
        ownerName = a.ownerName;
    }
    ~Apartment(){
        delete ownerName;
    }
    void display() const {
        cout <<"Apartment ID: "<<id << endl;
        cout <<"Address: " << address<< endl;
        cout <<"Owner: " << *ownerName << endl;
    }

};


int main(){
    Apartment apt1("1000","App no 201 off street","Irfan");
    apt1.display(); 
    Apartment apt2 = apt1;
    apt2.display();

    return 0;
}