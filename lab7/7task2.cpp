#include<iostream>
using namespace std;

class Product{
    protected:
        int id;
        string name;
        double price;
        int qty;
    public:
        Product(int id,string name,double price,int qty=0):
        id(id),name(name),price(price),qty(qty){}

        virtual void applydiscount(double amount){
            price-=amount;
        }

        virtual void calculatetotalprice(int qty){
           price*=qty;
        }

        virtual void displayinfo(){
            cout<<"----------------"<<endl;
            cout<<"Product ID: "<<id<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Price: "<<price<<endl;
            cout<<"Stock quantity: "<<qty<<endl;
        }
        Product operator+(const Product& obj){
            double total;
            total=price+obj.price;
            cout<<"Total price is: "<<total<<endl;
        }

};

class Electronics:public Product{
    private:
        int warranty;
        string brand;
    public:
        Electronics(int id,string name,double price,int warranty,string brand,int qty=0):
        Product(id,name,price,qty),warranty(warranty),brand(brand){}

        void displayinfo(){
                Product::displayinfo();
                cout<<"Warranty Period: "<<warranty<<" years"<<endl;
                cout<<"Brand: "<<brand<<endl;
        }

};

class Clothing:public Product{
    private:
        int size;
        string color;
        string fabric;
    public:
        Clothing(int id,string name,double price,int size,string color,string fabric,int qty=0):
        Product(id,name,price,qty),size(size),color(color),fabric(fabric){}

        void applydiscount(double amount){
            Product::applydiscount(amount);
            cout<<"Discounted Price of cloth is: "<<price<<endl;
        }

};

class FoodItem:public Product{
    private:
        int calories;
        string expirationdate;
    public:
        FoodItem(int id,string name,double price,int calories,string expirationdate,int qty=0):
        Product(id,name,price,qty),calories(calories),expirationdate(expirationdate){}

        void calculatetotalprice(int qty){
            Product::calculatetotalprice(qty);
            cout<<"Total Price of food is: "<<price<<endl;
        }

};

class Book:public Product{
    private:
        string author;
        string genre;
    public:
        Book(int id,string name,double price,string author,string genre,int qty=0):
        Product(id,name,price,qty),author(author),genre(genre){}

        void displayinfo(){
            Product::displayinfo();
            cout<<"Author: "<<author<<endl;
            cout<<"Genre: "<<genre<<endl;
    }

};

int main(){

    Electronics e1(101, "Laptop", 1200.50, 2, "Dell", 5);
    Clothing c1(201, "T-Shirt", 25.99, 'L', "Red", "Cotton", 10);
    FoodItem f1(301, "Chocolate", 5.49, 250, "12-12-2025", 20);
    Book b1(401, "The Alchemist", 15.75, "Paulo Coelho", "Fiction", 8);

    Product* ptr;
    ptr=&e1;
    ptr->displayinfo();
    ptr=&c1;
    c1.applydiscount(5);
    ptr=&f1;
    ptr->calculatetotalprice(10);
    ptr=&b1;
    ptr->displayinfo();

    c1.calculatetotalprice(5);
    cout<<"Bulk purchase of Food and cloth"<<endl;
    c1+f1;
    return 0;
}