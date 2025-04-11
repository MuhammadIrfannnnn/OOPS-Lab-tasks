#include<iostream>
#include<math.h>
using namespace std;

class Complex{
private:
    int real;
    int imaginary;
public:
    Complex(int r=0,int i=0):real(r),imaginary(i){}

    Complex operator+(Complex& C){
        Complex temp;
        temp.real=real+C.real;
        temp.imaginary=imaginary+C.imaginary;
        return temp;
    }
    Complex operator-(Complex& C){
        Complex temp;
        temp.real=real-C.real;
        temp.imaginary=imaginary-C.imaginary;
        return temp;
    }
    Complex operator*(Complex& C){
        Complex temp;
        temp.real=real*C.real;
        temp.imaginary=imaginary*C.imaginary;
        return temp;
    }
    Complex operator/(Complex& C){
        Complex temp;
        temp.real=real/C.real;
        temp.imaginary=imaginary/C.imaginary;
        return temp;
    }

    friend ostream& operator<<(ostream& out,const Complex&C);

    friend double magnitude(Complex&C);


};
ostream& operator<<(ostream& out,const Complex&C){
    out<<C.real<<" + "<<C.imaginary<<"i"<<endl;
}
double magnitude(Complex&C){
    int mag;
    mag=C.real*C.real;
    mag+=C.imaginary*C.imaginary;
    return sqrt(mag);
}

int main(){
    Complex C1(5,4);
    Complex C2(2,3);
    Complex C3;
    C3=C1+C2;
    cout<<C3;
    C3=C1-C2;
    cout<<C3;
    C3=C1*C2;
    cout<<C3;
    C3=C1/C2;
    cout<<C3;

    cout<<magnitude(C3)<<endl;


}