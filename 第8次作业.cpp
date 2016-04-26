#include<iostream>
#include<math.h>
using namespace std;
class Point
{
public:
	Point(int x,int y);
	~Point()
	{cout<<"Destucting Point.."<<endl;}
	int returnX(){ return x;}
	int returnY(){ return y;}
private:
	int x,y;
};
Point::Point(int x,int y)
{
	cout<<"Constucting Point.."<<endl;
}
class Shape
{
public:
	Shape(int x,int y);	
	//把图形看做质点，x,y表示质点的坐标
	~Shape()
	{cout<<"Destucting Shape.."<<endl;}
	void moveTo(int xx, int yy);
	virtual float Area()=0;
	//用到了后面的知识
private:
	Point position;
	int x,y;
};
Shape::Shape(int x,int y):position(x,y)
{	//因为Shape中的Position没有默认构造函数
	cout<<"Constucting Shape.."<<endl;
}
void Shape::moveTo(int xx,int yy)
{
	xx = position.returnX();
	yy = position.returnY();
}
class Triangle:public Shape
{
public:
    Triangle(float a1,float b1,float c1):Shape(0,0)
    {
		cout<<"Constucting Triangle.."<<endl;
        a=a1;
        b=b1;
        c=c1;
    }
	~Triangle()
	{cout<<"Destucting Triangle.."<<endl;}
   float Area()
   {
		float p=(a+b+c)/2;
        return (float)sqrt(p*(p-a)*(p-b)*(p-c));
	}
private:
    float a;
    float b;
    float c;
};
class Rectangle:public Shape
{
public:
    Rectangle(float a1,float b1):Shape(0,0)
    {
		cout<<"Constucting Rectangle.."<<endl;
        a=a1;
        b=b1;
    }
	~Rectangle()
	{cout<<"Destucting Rectangle.."<<endl;}
    float Area()
    {
        return (float)a*b;
    }
private:
    float a;
    float b;
};
int main()
{
    Triangle e(3.0,4.0,5.0);
	cout<<"三角形面积："<<e.Area()<<endl;
    Rectangle r(1.0,2.0);
	cout<<"长方形面积："<<r.Area()<<endl;
	return 0;
}