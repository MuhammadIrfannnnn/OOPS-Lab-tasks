#include<iostream>
using namespace std;

class Ticket{
    protected:
        int id;
        string name;
        double price;
        string date;
        string destination;
    public:
        Ticket(int id,string name,double price,string date,string destination):
        id(id),name(name),price(price),date(date),destination(destination){}

            virtual void reserve(){
                cout<<"Ticket reserved for "<<name<<" on"<<date<<" to "<<destination<<endl;
            }
            virtual void cancel(){
                cout<<"Ticket cancel for "<<name<<endl;
            }
            virtual void displayinfo(){
                cout<<"----------------------"<<endl;
                cout<<"Ticket ID: "<<id<<endl;
                cout<<"Passenger Name: "<<name<<endl;
                cout<<"Price: "<<price<<endl;
                cout<<"Date: "<<date<<endl;
                cout<<"Destination: "<<destination<<endl;
            }
};

class FlightTicket:public Ticket{
    private:
        string airlinename;
        int flightnumber;
        char seatclass;
    public:
        FlightTicket(int id,string name,double price,string date,string destination,string airlinename,int flightnumber,char seatclass):
        Ticket(id,name,price,date,destination),airlinename(airlinename),flightnumber(flightnumber),seatclass(seatclass){}

        void displayinfo(){
            Ticket::displayinfo();
            cout<<"Airline Name: "<<airlinename<<endl;
            cout<<"Flight Number: "<<flightnumber<<endl;
            cout<<"SeaT Class: "<<seatclass<<endl;
        }

};

class TrainTicket:public Ticket{
    private:
        int trainnumber;
        string coachtype;
        string departuretime;
    public:
        TrainTicket(int id,string name,double price,string date,string destination,int trainnumber,string coachtype,string departuretime):
        Ticket(id,name,price,date,destination),trainnumber(trainnumber),coachtype(coachtype),departuretime(departuretime){}

        void reserve(){
            cout<<"Train Ticket reserved for "<<name<<" on"<<date<<" to "<<destination<<" at time "<<departuretime<<endl;
            cout<<"Auto assigning seats: "<<endl;
            int seatnumber=rand()%100 +1;
            cout<<"Seat Number is: "<<seatnumber<<endl;
        }
};

class BusTicket:public Ticket{
    private:
        string buscompany;
        int seatnumber;
    public:
        BusTicket(int id,string name,double price,string date,string destination,string buscompany,int seatnumber):
        Ticket(id,name,price,date,destination),buscompany(buscompany),seatnumber(seatnumber){}

      void cancel(){
        cout<<"Bus Ticket cancel for "<<name<<endl;
        cout<<"Refunding Ticket Price "<<price<<endl;
      }
};

class ConcertTicket:public Ticket{
    private:
        string artistname;
        string venue;
        string seattype;
    public:
        ConcertTicket(int id,string name,double price,string date,string destination,string artistname,string venue,string seattype):
        Ticket(id,name,price,date,destination),artistname(artistname),venue(venue),seattype(seattype){}

        void displayinfo(){
            Ticket::displayinfo();
            cout<<"Artist Name: "<<artistname<<endl;
            cout<<"Venue: "<<venue<<endl;
            cout<<"Seat Type: "<<seattype<<endl;
        }

};

int main(){
    Ticket* ptr;
    FlightTicket F(100,"Irfan",50000,"30/9/2025","New York","Emirates",265,'A');
    TrainTicket T(101,"Hasan",20000,"7/8/2025","Lahore",127,"Business Class","5:00 PM");
    BusTicket B(102,"Abdullah",12000,"9/12/2025","Quetta","Daewoo",55);
    ConcertTicket C(103,"Hafiz",2500,"10/4/2025","karachi","Young Stunners","DHA-PHASE 6","VIP");
    ptr=&F;
    ptr->displayinfo();
    ptr=&T;
    ptr->reserve();
    ptr=&B;
    ptr->cancel();
    ptr=&C;
    ptr->displayinfo();
    
    return 0;
}
