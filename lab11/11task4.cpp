#include<iostream>
#include<stdexcept>
using namespace std;

class DataBaseException:public exception{
protected:
string msg;
public:
DataBaseException(string msg):msg(msg){}

string what(){
    return msg;
}

};
class ConnectionBasedException:public DataBaseException{
public:
ConnectionBasedException(string msg):DataBaseException(msg){}


};
class QueryTimeoutException:public DataBaseException{
    public:
    QueryTimeoutException(string msg):DataBaseException(msg){}
    };

    template<typename T>
    class DataBaseConnector{
        private:
        T database;
        public:
        DataBaseConnector(T database):database(database){}
        void connect(){
        if(database=="invalid_db"){
            throw ConnectionBasedException("A database Error Occured");
        }
        else if(database=="slow_db"){
            throw QueryTimeoutException("A database Error Occured");
        }
        else{
            cout<<"Database Connected"<<endl;
        }
    }

    };
    int main(){
        try{
            DataBaseConnector<string> db1("invalid_db");
            cout<<"Attempting to invalid database"<<endl;
            db1.connect();
        }catch(ConnectionBasedException &e){
            cout<<"Caught Connection Failed Exception : "<<e.what()<<endl;
        }
        try{
            DataBaseConnector<string> db2("slow_db");
            cout<<"Attempting to slow database"<<endl;
            db2.connect();
        }catch(QueryTimeoutException &e){
            cout<<"Caught a general database Exception : "<<e.what()<<endl;
        }
        return 0;
    }