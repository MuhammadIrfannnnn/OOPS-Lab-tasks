#include<iostream>
#include<string>
using namespace std;


class Wallet
{
private:
    string ownername;
    double totalbalance;
    string transactionhistory[50];
public:
int count;
    void setdetails(string o,double t){
        ownername=o;
        totalbalance=t;
        count=0;
    }     
    void addmoney(int a){
        totalbalance+=a;
        transactionhistory[count++]="Added: "+to_string(a);
    }
    void spendmoney(int s){
        if(s>totalbalance){
            cout<<"Unsufficient balance"<<endl;
        }
        else{
        totalbalance-=s;
        transactionhistory[count++]="Spend: "+to_string(s);
        }
    }
    void displaytransaction(){
        if(count==0){
            cout<<"No transaction yet."<<endl;
        }
        else{
            cout<<"Transaction History"<<endl;
        for(int i=0;i<count;i++){
            cout<<transactionhistory[i]<<endl;
        }
    }
    }
    

};

int main(){
    int amount;
    double balance;
    cout<<"Enter balance: ";
    cin>>balance;
    Wallet saad;
    saad.setdetails("saad",balance);
    int choice;
    cout<<"1.Add Money"<<endl<<"2.Spend Money"<<endl<<"3.display transaction history"<<endl<<"4.exit"<<endl;
  do
  {
    cout<<"Enter choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"Enter amount: ";
        cin>>amount;
        saad.addmoney(amount);
        break;
    case 2:
        cout<<"Enter amount: ";
        cin>>amount;
        saad.spendmoney(amount);
        break;
    case 3:
        saad.displaytransaction();
        break;
    case 4:
        break;
    
    default:
        cout<<"Invalid choice!"<<endl;
        break;
    }
    
  } while (choice!=4);

  return 0;
  
    

}