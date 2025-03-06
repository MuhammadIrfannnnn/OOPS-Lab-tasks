#include<iostream>
using namespace std;

class Employee{
    protected:
        string name;
        float salary;
    public:
        Employee(string name,float salary):name(name),salary(salary){}
        void displayDetails(){
            cout<<"--------------------------"<<endl;
            cout<<"Employee name: "<<name<<endl;
            cout<<"Employee Salary: "<<salary<<endl;
        }

};

class Manager:public Employee{
    protected:
        float bonus;
    public:
        Manager(string name,float salary,float bonus):
        Employee(name,salary),bonus(bonus){}

        void displayDetails(){
            Employee::displayDetails();
            cout<<"Bonus: "<<bonus<<endl;
        }
};

int main(){
    Employee E1("Ali",50000);
    E1.displayDetails();
    Manager M1("Irfan",100000,25000);
    M1.displayDetails();
}