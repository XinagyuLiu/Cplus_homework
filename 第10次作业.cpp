#include<iostream>
#include<math.h>
using namespace std;
class Point
{
public:
	Point(int xx=0,int yy=0){ x=xx; y=yy; }
	~Point(){}
private:
	int x,y;
};
class Shape
{
public:
	Shape(int x,int y);	
	~Shape(){}
	void moveTo(int xx, int yy);
	virtual float Area()=0;
	virtual void whoami()
	{ cout<<"This is a Shape."<<endl; }
	virtual void ShowPosition()
	{ cout<<"Position:("<<x<<","<<y<<")"<<endl;}
private:
	Point position;
	int x,y;
};
//¹¹Ôìposition
Shape::Shape(int xx,int yy):position(xx,yy){}
class Triangle:public Shape
{
public:
    Triangle(int xx,int yy,double aa):Shape(xx,yy)
    {
		x = xx;
		y = yy;
		a = aa;
    }
	~Triangle(){}
   float Area()
   {
		float p= (1.732/4)*a*a;
        return p;
	}
	void whoami()
	{ cout<<"This is a Triangle."<<endl; }
	void ShowPosition()
	{ cout<<"Position:("<<x<<","<<y<<")"<<endl;}
private:
	int x,y;
	double a;
};
class Rectangle:public Shape
{
public:
    Rectangle(int xx,int yy,float a1,float b1):Shape(xx,yy)
    {
		x = xx;
		y = yy;
        a=a1;
        b=b1;
    }
	~Rectangle(){}
    float Area()
    {
        return (float)a*b;
    }
	void whoami()
	{ cout<<"This is a Rectangle."<<endl; }
	void ShowPosition()
	{ cout<<"Position:("<<x<<","<<y<<")"<<endl;}
private:
	int x,y;
    float a;
    float b;
};
int main()
{
	Triangle tri1(10, 10, 8);
	Rectangle rect(15, 20, 6, 10);
	Triangle tri2(20, 20, 10);
	Shape *shapes[3] = { &tri1,&rect,&tri2 };
	double sum_area=0.0;
	for(int i=0;i<3;i++)
	{
		shapes[i]->whoami();
		shapes[i]->ShowPosition();
		cout<<"Area:"<<shapes[i]->Area()<<endl;
		sum_area += shapes[i]->Area();
	}
	cout<<"Toal_Area:"<<sum_area<<endl;	
	return 0;
}