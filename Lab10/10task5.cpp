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
        else if(name=="HybridTruck"){
            size_t pos1=specstr.find(':');
            size_t pos2=specstr.find('|');
            size_t pos3=specstr.rfind(':');
            if(pos1!=string::npos && pos2!=string::npos && pos3!=string::npos){
                string cargostr=specstr.substr(pos1+1,pos2-pos1-1);
                string batterystr=specstr.substr(pos3+1);
                int cargo=stoi(cargostr);
                int battery=stoi(batterystr);
                cout<<"Cargo in Int: "<<cargo<<" Battery in int: "<<battery<<endl;
            }
        }
        else{
            cout<<"Error vehicle not found"<<endl;
        }
        cout<<"Name: "<<name<<" ID: "<<id<<" Model: "<<model<<" Year: "<<year<<" Specification: "<<specstr<<" Certification: "<<cert<<endl;
    }
    file.close();
    return 0;
    

}