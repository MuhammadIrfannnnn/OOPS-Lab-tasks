#include<iostream>
using namespace std;

class Person{
    protected:
        string name;
        int age;
        string contact;
        string address;
    public:
    Person(string name,int age,string contact,string address=""):
    name(name),age(age),contact(contact),address(address){}

        virtual void displayinfo(){
            cout<<"---------------------"<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Age: "<<age<<endl;
            cout<<"Contact: "<<contact<<endl;
            if(!address.empty()){
            cout<<"Address: "<<address<<endl;
            }
        }
        virtual void updateinfo(string name,int age,string contact,string address){
            this->name=name;
            this->age=age;
            this->contact=contact;
            this->address=address;
        }

};

class Patient:public Person{
    private:
        int patientID;
        string medicalhistory;
        string doctorassigned;
    public:
        Patient(string name,int age,string contact,int patientID,string medicalhistory,string doctorassigned,string address=""):
        Person(name,age,contact,address),patientID(patientID),medicalhistory(medicalhistory),doctorassigned(doctorassigned){}

        void displayinfo(){
            Person::displayinfo();
            cout<<"Patient ID: "<<patientID<<endl;
            cout<<"Medical History: "<<medicalhistory<<endl;
            cout<<"Doctor Assigned: "<<doctorassigned<<endl;
        }
};

class Doctor:public Person{
    private:
        string specialization;
        double fee;
        int patientlist;
    public:
        Doctor(string name,int age,string contact,string specialization,double fee,int patientlist,string address=""):
        Person(name,age,contact,address), specialization(specialization),fee(fee) ,patientlist(patientlist) {}

        void displayinfo(){
            Person::displayinfo();
            cout<<"Specialization: "<<specialization<<endl;
            cout<<"Fee: "<<fee<<endl;
            cout<<"Number of patients: "<<patientlist<<endl;
        }
};

class Nurse:public Person{
    private:
        string assignedWard;
        string shifttimings;
    public:
        Nurse(string name,int age,string contact,string assignedWard,string shifttimings,string address=""):
        Person(name,age,contact,address),assignedWard(assignedWard),shifttimings(shifttimings){}

        void displayinfo(){
            Person::displayinfo();
            cout<<"Assigned Ward: "<<assignedWard<<endl;
            cout<<"Shift Timings: "<<shifttimings<<endl;
        }
};

class Administrator : public Person {
    private:
        string department;
        double salary;
    
    public:
        Administrator(string name, int age, string contact, string department, double salary, string address = "")
            : Person(name, age, contact, address), department(department), salary(salary) {}
    
        void displayinfo() {
            Person::displayinfo();
            cout << "Administrator Department: " << department << endl;
            cout << "Salary: $" << salary << endl;
        }
        void updateinfo(string n, int a, string c, string dept, double sal,string addr) {
            Person::updateinfo(n, a, c, addr); 
            department = dept;
            salary = sal;
        }
    };



int main(){
    Person* ptr;

    Patient p1("Ali", 35, "123456789", 101, "Diabetes", "Dr. Ahmed", "Karachi");
    Doctor d1("Dr. Ahmed", 45, "987654321", "Cardiology", 150.0, 20, "Islamabad");
    Nurse n1("Iqra", 30, "567894321", "Ward A", "Night", "Lahore");
    Administrator a1("Junaid", 50, "321654987", "HR", 75000.0, "Karachi");
    ptr=&p1;
    ptr->displayinfo();
    ptr=&d1;
    ptr->displayinfo();
    ptr=&n1;
    ptr->displayinfo();
    a1.updateinfo("Junaid", 51, "321654987", "HR", 80000, "Karachi");
    ptr=&a1;
    ptr->displayinfo();


    return 0;
}