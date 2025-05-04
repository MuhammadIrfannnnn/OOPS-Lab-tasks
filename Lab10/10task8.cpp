#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ofstream out("config.txt");
    out<<"AAAAABBBBBCCCCC";
    out.close();

    fstream file("config.txt",ios::in | ios::out);
    if(!file){
        cout<<"Error"<<endl;
        return 1;
    }
    file.seekp(5);
    file.write("XXXXX",5);
    file.close();

    ifstream in("config.txt");
    string line;
    getline(in,line);
    cout<<"Updated file: "<<line<<endl;
    in.close();

    return 0;

}