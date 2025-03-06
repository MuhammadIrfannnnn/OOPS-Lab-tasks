#include<iostream>
using namespace std;

class Person{
    protected:
        string name;
        int age;
    public:
        Person(string name,int age):name(name),age(age){}
        void displayDetails(){
            cout<<"--------------------------"<<endl;
            cout<<"Name: " <<name<<endl;
            cout<<"Age: "<<age<<endl;
        }

};

class Teacher:virtual public Person{
    protected:
        string subjects;
    public:
        Teacher(string name,int age,string subjects):
        Person(name,age),subjects(subjects){}

        void displayDetails(){
            Person::displayDetails();
            cout<<"Subject: "<<subjects<<endl;
        }
};

class Researcher:virtual public Person{
    protected:
        string researchArea;
    public:
        Researcher(string name,int age,string researchArea):
        Person(name,age),researchArea(researchArea){}

        void displayDetails(){
            Person::displayDetails();
            cout<<"Research Area: "<<researchArea<<endl;
        }
};

class Professor:public Researcher,public Teacher{
    protected:
        int publications;
    public:
            Professor(string name,int age,string subjects,string researchArea,int publications):
            Person(name,age),Researcher(name,age,subjects),Teacher(name,age,researchArea),publications(publications){}
            void displayDetails(){
               Person::displayDetails();
               cout<<"Subject: "<<subjects<<endl;
               cout<<"Research Area: "<<researchArea<<endl;
               cout<<"Publications: "<<publications<<endl;
            }
        };

int main(){
    Professor prof("Irfan",20,"Mathematics", "Machine Learning", 20);
    prof.displayDetails(); 

    return 0;
}
