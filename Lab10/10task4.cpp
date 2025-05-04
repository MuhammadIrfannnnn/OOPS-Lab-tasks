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
    string specstr;
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
        getline(info,specstr,',');
        getline(info,cert,',');

        if(name=="AutonomousCar"){
            size_t pos=specstr.find(':');
            if(pos!=string::npos){
                string swstr=specstr.substr(pos+1);
                float sw=stof(swstr);
                cout<<"SW in float: "<<sw<<endl;
            }
        }
        else if(name=="ElectricVehicle"){
            size_t pos=specstr.find(':');
            if(pos!=string::npos){
                string batstr=specstr.substr(pos+1);
                float bat=stof(batstr);
                cout<<"Battery in float: "<<bat<<endl;
            }
        }
        cout<<"Name: "<<name<<" ID: "<<id<<" Model: "<<model<<" Year: "<<year<<" Specification: "<<specstr<<" Certification: "<<cert<<endl;
    }
    file.close();
    return 0;
    

}