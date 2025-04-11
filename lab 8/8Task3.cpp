#include <iostream>
using namespace std;

class Vector2D{
	private:
		float x;
		float y;
	public:
		Vector2D(float x,float y):x(x),y(y){}
		Vector2D operator+(Vector2D& v1){
		return Vector2D(x+v1.x,y+v1.y);
		}
		Vector2D operator-(Vector2D& v1){
			return Vector2D(x-v1.x,y-v1.y);
		}
	Vector2D operator*(Vector2D& v1){
			return Vector2D(x*v1.x,y*v1.y);
		}
		friend ostream& operator<<(ostream& out,Vector2D v1);
		 friend void dotproduct(Vector2D& v1,Vector2D& v2);
		
};

   ostream& operator<<(ostream& out,Vector2D v1){
			out<<"vector = ("<<v1.x<<","<<v1.y<<")"<<endl;
			return out;
		}

    void dotproduct(Vector2D& v1, Vector2D& v2){
    float dotproduct =(v1.x*v2.x)+(v1.y*v2.y);
    cout<<"dotproduct: "<<dotproduct<<endl;
	}

int main(){
	Vector2D v1(3,6);
	Vector2D v2(7,10);
	Vector2D sum=	v1+v2;
	Vector2D diff= v1-v2;
	Vector2D multiply= v1*v2;
	cout<<sum;
	cout<<diff;
	cout<<multiply;
	dotproduct(v1,v2);
    return 0;
}