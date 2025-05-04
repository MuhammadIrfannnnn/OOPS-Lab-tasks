#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ifstream file("Vehicles.txt");
    if(!file.is_open()){
        cout<<"Error"<<endl;
        return 1;
    }

    string line;

    while (getline(file,line)){
        if(line.empty() || (line.size()>1 && line[0]=='/' && line[1]=='/')){
            continue;
        }
        cout<<line<<endl;
    }
    file.close();
    return 0;
    

}