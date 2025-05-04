#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ifstream in("data_records.txt");
    if(!in){
        cout<<"Error"<<endl;
        return 1;
    }
    in.seekg(20,ios::beg);
     string line;
     getline(in,line);
     cout<<"Third Record: "<<line<<endl;

     in.close();
     return 0;
}