#include<iostream>
#include<stdexcept>
using namespace std;

class OverFlowException:public exception{

};
class UnderFlowException:public exception{
    
};

template<typename T>
class Queue{
private:
T*data;
int capacity;
int current;
public:
Queue(int capacity):capacity(capacity),current(0){
    data=new T[capacity];
}
void Enque(T value){
    if(current>=capacity){
        throw OverFlowException();
    }
    data[current++]=value;
    cout<<"Data Enqued"<<endl;
}

void deque(){
    if(current<=0){
        throw UnderFlowException();
    }
    for(int i=0;i<current-1;i++){
        data[i]=data[i+1];
    }
    current--;
    cout<<"Data Dequed"<<endl;
}

};

int main(){
    Queue<int> Q(2);
    try{
        
        Q.Enque(1);
        Q.Enque(2);
        cout<<"Attempting to Enque in a full QUEUE"<<endl;
        Q.Enque(3);
    }catch(OverFlowException& e){
        cout<<"Caught Overflow Exception "<<e.what()<<endl;
    }
    try{
        Q.deque();
        Q.deque();
        cout<<"Attempting to Deque From a empty QUEUE"<<endl;
    Q.deque();
    }catch(UnderFlowException &e){
        cout<<"Caught Underflow Exception "<<e.what()<<endl;
    }
    return 0;
}




