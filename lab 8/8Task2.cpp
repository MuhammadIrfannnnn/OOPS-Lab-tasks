#include <iostream>
using namespace std;

class Account{
    private:
	    int accountnumber;
	    float balance;
	public:
		Account(int number,float bal):accountnumber(number),balance(bal){}
    friend void transferfunds(float num,Account& a1,Account& a2);
    friend class Manager;		
};

void transferfunds(float num,Account& a1,Account& a2){
	if(a1.balance>num){
		a1.balance-=num;
		a2.balance+=num;
	}
	else{
		cout<<"Insuffiecnt funds"<<endl;
	}
}

class Manager{
	public:
	void displaydetails(Account& a){
			cout<<"Account number: "<<a.accountnumber<<"\nbalance: "<<a.balance<<endl;
		}
	void addbalance(float num,Account& a){
		a.balance+=num;
	}
	void withdraw(float num,Account& a){
		a.balance-=num;
	}
};

int main(){
	Manager M;
	Account A1(100,1000);
	Account A2(101,2000);
	M.addbalance(100,A1);
	M.withdraw(100,A1);
	transferfunds(500,A1,A2);
	M.displaydetails(A1);
	M.displaydetails(A2);

}