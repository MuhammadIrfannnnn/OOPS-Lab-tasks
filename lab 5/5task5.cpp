#include<iostream>
using namespace std;

class Doctors{
    private:
        string name;
        string specialization;
        string experience;
    public:
        Doctors(string name,string specialization,string experience){
            this->name=name;
            this->specialization=specialization;
            this->experience=experience;
        }

    string getname(){
        return name;
    }

};

class Hospital{
    private:
        string name;
        string address;
        Doctors** assigneddoctors;
        int numdoctors;
    public:
        Hospital(string name,string address){
            this->name=name;
            this->address=address;
            numdoctors=0;
            assigneddoctors=nullptr;
        }

        void assigndoctor(Doctors* D){
            Doctors** temp=new Doctors*[numdoctors+1];
            for(int i=0;i<numdoctors;i++){
                temp[i]=assigneddoctors[i];
            }
            delete[] assigneddoctors;
            temp[numdoctors]=D;
            numdoctors++;
            assigneddoctors=temp;
        }

        void display(){
            cout<<"--------------------------"<<endl;
            cout<<"Hospital Name: "<<name<<endl;
            cout<<"Hospital Address: "<<address<<endl;
            if(assigneddoctors!=nullptr){
            cout<<"Assigned Doctors: "<<endl;
            for(int i=0;i<numdoctors;i++){
                cout<<i+1<<". "<<assigneddoctors[i]->getname()<<endl;
               }
            }
            else
            {
                cout<<"No current Doctors"<<endl;
            }
            

        }

        ~Hospital() {
            delete[] assigneddoctors; 
        }

};

int main(){
    Hospital H1("Children's","DHA");
    Doctors D1("Irfan","heart","3 year");
    Doctors D2("Hasan","Lungs","5 year");
    H1.assigndoctor(&D1);
    H1.display();
    H1.assigndoctor(&D2);
    H1.display();
}