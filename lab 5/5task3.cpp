#include<iostream>
using namespace std;

class Employee{
    private:
        string name;
        string designation;
    public:
        Employee(string name,string designation){
            this->name=name;
            this->designation=designation;
        }

    string getname(){
        return name;
    }

};

class Project{
    private:
        string title;
        string deadline;
        Employee** assignedemployee;
        int numemployees;
    public:
        Project(string title,string deadline){
            this->title=title;
            this->deadline=deadline;
            numemployees=0;
            assignedemployee=nullptr;
        }

        void addemployee(Employee* E){
            Employee** temp=new Employee*[numemployees+1];
            for(int i=0;i<numemployees;i++){
                temp[i]=assignedemployee[i];
            }
            delete[] assignedemployee;
            temp[numemployees]=E;
            numemployees++;
            assignedemployee=temp;
        }

        void display(){
            cout<<"--------------------------"<<endl;
            cout<<"Project Title: "<<title<<endl;
            cout<<"Project Dealine: "<<deadline<<endl;
            if(assignedemployee!=nullptr){
            cout<<"Assigned Employees: "<<endl;
            for(int i=0;i<numemployees;i++){
                cout<<i+1<<". "<<assignedemployee[i]->getname()<<endl;
               }
            }
            else
            {
                cout<<"No current employees"<<endl;
            }
            

        }

        ~Project() {
            delete[] assignedemployee; 
        }

};

int main(){
    Project P1("OOPS","7/march/2025");
    Employee E1("Irfan","Leader");
    Employee E2("Hasan","Designer");
    P1.addemployee(&E1);
    P1.display();
    P1.addemployee(&E2);
    P1.display();
}