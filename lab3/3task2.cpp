#include<iostream>
using namespace std;

class Library{
private:
    string booklist[50];
    string available[50];
    string borrowed[50];
    int count=0;
    int availablecount=0;
    int borrowedcount=0;
public:
    void addbook(string b){
        booklist[count++]=b;
        available[availablecount++]=b;
        cout<<"Book: '"<<b<<"' added successfully"<<endl;
    }
    void lendbook(string b){
        for(int i=0;i<availablecount;i++){
            if(available[i]==b){
                borrowed[borrowedcount++]=b;

                for(int j=i;j<availablecount-1;j++){
                    available[j]=available[j+1];
                }
                availablecount--;
                cout<<"Book '"<<b<<"' lend successfully"<<endl;
                return;
            }
        }
        cout<<"Book not available"<<endl;
    }

    void returnbook(string b){
        for(int i=0;i<borrowedcount;i++){
            if(borrowed[i]==b){
                available[availablecount++]=b;

                for(int j=i;j<borrowedcount-1;j++){
                    borrowed[j]=borrowed[j+1];
                }
                borrowedcount--;
                cout<<"Book '"<<b<<"' return successfully"<<endl;
                return;
            }
        }
        cout<<"wrong book"<<endl;
    }

    void displaybook(){
        if(availablecount>0){
        cout<<"Available books: "<<endl;
        for(int i=0;i<availablecount;i++){
            cout<<available[i]<<endl;
        }
    }
    else{
        cout<<"No available books"<<endl;
    }
}
    
};

int main(){
    Library A;
    A.addbook("Prisoner of zenda");
    A.addbook("1984");
    A.addbook("Harry Potter");
    A.lendbook("1984");
    A.displaybook();
    A.returnbook("1984");
    A.displaybook();

    return 0;
}


