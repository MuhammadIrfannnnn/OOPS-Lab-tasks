#include<iostream>
using namespace std;

class Products{
    private:
        int id;
        string name;
        int stock;
    public:
        Products(int id,string name,int stock){
            this->id=id;
            this->name=name;
            this->stock=stock;
        }

    string getname(){
        return name;
    }
    int getid(){
        return id;
    }

};

class Inventory{
    private:
        string name;
        Products** product;
        int  numproduct;
    public:
        Inventory(string name){
            this->name=name;
           product=nullptr;
           numproduct=0;
        }

        void addProduct(Products* P){
            Products** temp=new Products*[numproduct+1];
            for(int i=0;i<numproduct;i++){
                temp[i]=product[i];
            }
            delete[] product;
            temp[numproduct]=P;
            numproduct++;
            product=temp;
        }

        void sortByName() {
            for (int i = 0;i<numproduct-1;i++) {
                for (int j=i+1;j<numproduct;j++) {
                    if (product[i]->getname()>product[j]->getname()) {
                        swap(product[i], product[j]);
                    }
                }
            }
        }

        void display(){
            cout<<"--------------------------"<<endl;
            cout<<"Inventory Name: "<<name<<endl;
            if(product!=nullptr){
            cout<<"Products: "<<endl;
            for(int i=0;i<numproduct;i++){
                cout<<i+1<<". "<<product[i]->getname()<<endl;
               }
            }
            else
            {
                cout<<"No Products"<<endl;
            }
            

        }

        void searchByID(int id){
            for (int i = 0; i <numproduct; i++) {
                if (product[i]->getid() == id) {
                    cout<<"product is: "<<product[i]->getname()<<endl;
                    return;
                }
            }
            cout << "Product not found!" << endl;
        }

        ~Inventory() {
            delete[] product; 
        }

};

int main() {
    Inventory warehouse("Warehouse A");

    Products p1(101, "Table", 10);
    Products p2(102, "Chair", 15);
    Products p3(103, "Lamp", 5);

    warehouse.addProduct(&p1);
    warehouse.addProduct(&p2);
    warehouse.addProduct(&p3);

    cout << "Before Sorting:\n";
    warehouse.display();

    warehouse.sortByName();
    
    cout << "\nAfter Sorting:\n";
    warehouse.display();
    cout << "\nSearching for Product with ID 102:\n";
    warehouse.searchByID(102);

    return 0;
}