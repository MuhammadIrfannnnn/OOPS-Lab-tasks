#include<iostream>
using namespace std;

class FitnessTracker{
    private:
        string username;
        int dailystepgoal;
        int stepstaken;
        float caloriesburned;
    public:
            void setusername(string name){
                username=name;
            }
            void setdailystep(int s){
                dailystepgoal=s;
                stepstaken=0;
                caloriesburned=0;
            }
            void logsteps(int st){
                stepstaken+=st;
                caloriesburned+=st*0.5;
            }
            void displayprogress(){
                cout<<"Name: "<<username<<endl;
                cout<<"daily steps goal: "<<dailystepgoal<<endl;
                cout<<"Steps Taken: "<<stepstaken<<endl;
                cout<<"Calories burned: "<<caloriesburned<<endl;
                if(stepstaken>=dailystepgoal){
                    cout<<"You have reached todays goal"<<endl;
                }
                else{
                    cout<<"You still need "<<dailystepgoal-stepstaken<<" steps"<<endl;
                }
            }
};

int main(){
    FitnessTracker laiba;
    laiba.setusername("Laiba");
    laiba.setdailystep(1000);
    laiba.logsteps(800);
    laiba.displayprogress();
    laiba.logsteps(200);
    laiba.displayprogress();

    return 0;
}