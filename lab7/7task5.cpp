#include<iostream>
using namespace std;


class Character{
    protected:
        int id;
        string name;
        int level;
        float health;
        string weapontype;

    public:
        Character(int id,string name,int level,float health,string weapontype=""):
        id(id),name(name),level(level),health(health),weapontype(weapontype){}

        virtual void attack(){
            cout<<name<<" Attacks"<<endl;
        }

        virtual void defend(){
            cout<<name<<" Defends"<<endl;
        }

        virtual void displaystats(){
            cout<<"ID: "<<id<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Level: "<<level<<endl;
            cout<<"Health Points: "<<health<<endl;
            if(!weapontype.empty()){
                cout<<"Weapon Type: "<<weapontype<<endl;
            }
        }

};

class Warrior:public Character{
    private:
        int armorstrength;
        int meleedamage;
    public:
    Warrior(int id,string name,int level,float health,int armorstrength,int meleedamage,string weapontype=""):
    Character(id,name,level,health,weapontype),armorstrength(armorstrength),meleedamage(meleedamage){}

        void attack(){
            cout << name <<"attacks and dealing "<< meleedamage << " melee damage!" << endl;
        }

};

class Mage:public Character{
    private:
        int manapoints;
        int spellpower;
    public:
    Mage(int id,string name,int level,float health,int manapoints,int spellpower,string weapontype=""):
    Character(id,name,level,health,weapontype),manapoints(manapoints),spellpower(spellpower){}
    
        void defend(){
            cout << name << " casts a magical barrier, reducing incoming damage!" << endl;
        }

};

class Archer:public Character{
    private:
        int arrowcount;
        int rangedaccuracy;
    public:
    Archer(int id,string name,int level,float health,int arrowcount,int rangedaccuracy,string weapontype=""):
    Character(id,name,level,health,weapontype),arrowcount(arrowcount),rangedaccuracy(rangedaccuracy){}
    
        void attack(){
            cout << name << " fires an arrow with " << rangedaccuracy << "% accuracy!" << endl;
        }

};

class Rogue:public Character{
    private:
        int stealthlevel;
        int agility;
    public:
    Rogue(int id,string name,int level,float health,int stealthlevel,int agility,string weapontype=""):
    Character(id,name,level,health,weapontype),stealthlevel(stealthlevel),agility(agility){}
    
        void displaystats(){
            Character::displaystats();
            cout<<"Stealth Level: "<<stealthlevel<<endl;
            cout<<"Agility: "<<agility<<endl;
        }

};

int main(){
    Warrior w1(101, "Conan", 10, 100, 50, 20,"Sword");
    Mage m1(102, "Merlin", 12, 80, 100, 40,"rods");
    Archer a1(103, "Legolas", 15, 90, 30, 85,"Bow and arrows");
    Rogue r1(104, "Shadow", 14, 85, 95, 70,"guns");

    Character* ptr;

    ptr=&w1;
    ptr->attack();
    ptr=&m1;
    ptr->defend();
    ptr=&a1;
    ptr->attack();
    ptr=&r1;
    ptr->displaystats();

    return 0;
}

