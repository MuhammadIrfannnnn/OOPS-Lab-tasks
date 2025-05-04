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

        void writefile(const char* file){
            ofstream out(file,ios::binary);
            if(out){
                out.write(reinterpret_cast<char*>(this),sizeof(*this));
                out.close();
            }
        }
        void readfile(const char* file){
            ifstream in(file,ios::binary);
            if(in){
                in.read(reinterpret_cast<char*>(this),sizeof(*this));
                in.close();
            }
        }
        void display(){
            cout<<"ID: "<<itemID<<" Name: "<<itemname<<endl;
        }


        

};

int main(){
    Inventory I1(100,"Shirt");
    Inventory I2;
    I1.writefile("Inventory.dat");
    I2.readfile("Inventory.dat");
    I2.display();
    return 0;
    
}
