#include<iostream>
using namespace std;

class Account{
    protected:
        int accnumber;
        float balance;
    public:
        Account(int accnumber,float balance):
        accnumber(accnumber),balance(balance){}

        void displayDetails(){
            cout<<"-----------------------------"<<endl;
            cout<<"Account Number: "<<accnumber<<endl;
            cout<<"Balance: "<<balance<<endl;

        }

};

class SavingsAccount:public Account{
    protected:
        float interestrate;
    public:
    SavingsAccount(int accnumber,float balance,float interestrate):
        Account(accnumber,balance),interestrate(interestrate){}
    void displayDetails(){
        Account::displayDetails();
        cout<<"Interest Rate: "<<interestrate<<endl;

    }

};

class CheckingAccount:public Account{
    protected:
        float overdraftlimit;
    public:
    CheckingAccount(int accnumber,float balance,float overdraftlimit):
        Account(accnumber,balance),overdraftlimit(overdraftlimit){}
    void displayDetails(){
        Account::displayDetails();
        cout<<"Over Draft Limit: "<<overdraftlimit<<endl;

    }

};

int main(){
    SavingsAccount A1(10045,50000,3000);
    A1.displayDetails();
    CheckingAccount A2(10065,100000,5000);
    A2.displayDetails();
}