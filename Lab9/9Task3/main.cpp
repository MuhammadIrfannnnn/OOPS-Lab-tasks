#include <iostream>
using namespace std;
#include "LectureCourse.h"
#include "LabCourse.h"

int main() {
    LectureCourse lec("SS4104", 3);
    LabCourse lab("SL4105", 1);

    Course*c1=&lec;
    Course*c2=&lab;
    c1->displayInfo();
    c1->calculateGrade();
    c2->displayInfo();
    c2->calculateGrade();
	}
