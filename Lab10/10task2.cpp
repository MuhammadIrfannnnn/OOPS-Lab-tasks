#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main(){
    ifstream file("Vehicles.txt");
    if(!file.is_open()){
        cout<<"Error"<<endl;
        return 1;
    }

    string line;
    string name;
    string id;
    string model;
    string year;
    string spec;
    string cert;

    

    while (getline(file,line)){
        if(line.empty() || (line.size()>1 && line[0]=='/' && line[1]=='/')){
            continue;
        }
        istringstream info(line);
        getline(info,name,',');
        getline(info,id,',');
        getline(info,model,',');
        getline(info,year,',');
        getline(info,spec,',');
        getline(info,cert,',');
        cout<<"Name: "<<name<<" ID: "<<id<<" Model: "<<model<<" Year: "<<year<<" Specification: "<<spec<<" Certification: "<<cert<<endl;
    }
    file.close();
    return 0;
    

}