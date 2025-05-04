#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Inventory{
    private:
        int itemID;
        char itemname[20];
    public:
    Inventory(){}
        Inventory(int ID,const char*Name):itemID(ID){
            strcpy(itemname,Name);
            itemname[sizeof(itemname)-1]='\0';
        }


        void display(){
            cout<<"ID: "<<itemID<<" Name: "<<itemname<<endl;
        }




};

int main(){
    Inventory I1(100,"Shirt");
   
        ofstream out("Inventory.dat",ios::binary);
            out.write((char*)&I1,sizeof(I1));
            out.close();
    Inventory I2;
        ifstream in("Inventory.dat",ios::binary);
            in.read((char*)&I2,sizeof(I2));
            in.close();
        
    I2.display();
    return 0;
    
}
