#include <iostream>
using namespace std;

class Student {
private:
    int id;
    string name;
    int* scores;
    int numScores;

public:
    Student(int id, string name, int scores[], int numScores) : id(id), name(name), numScores(numScores) {
        this->scores = new int[numScores]; 
        for (int i = 0; i < numScores; i++) {
            this->scores[i] = scores[i];  
        }
    }
    Student(const Student& obj) : id(obj.id), name(obj.name), numScores(obj.numScores) {
        this->scores = new int[obj.numScores];  
        for (int i = 0; i < obj.numScores; i++) {
            this->scores[i] = obj.scores[i];  
        }
    }

    ~Student() {
        delete[] scores;
    }

    void display() {
        cout << "------------------------------" << endl;
        cout << "Student ID: " << id << endl;
        cout << "Student Name: " << name << endl;
        cout << "Exam Scores: ";
        for (int i = 0; i < numScores; i++) {
            cout << scores[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int scores1[] = {85, 90, 78};
    Student S1(100, "Irfan", scores1, 3);  

    Student S2 = S1; 

    S1.display();
    S2.display();

    return 0;
}
