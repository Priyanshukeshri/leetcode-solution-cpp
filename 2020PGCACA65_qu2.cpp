#include <iostream>
#include <string.h>

using namespace std;

class point
 {
 	protected:
        int xCo, yCo;
    public:
        point() {
            cout<<"Construction called for class point"<<endl;
        }
        void getPoint() 
		{
           cout<<"Enter x Co ordinate: ";
           cin>>xCo;
           cout<<"Enter y Co ordinate: ";
           cin>>yCo; 
        }
        void print() 
		{
            cout<<"\nx Co ordinate is = "<<xCo<<endl;
            cout<<"y Co ordinate is = "<<yCo<<endl;
        }
        ~point() {
            cout<<"\nDestructor called for class point"<<endl;
        }
};

class circle : public point 
{
	protected:
        float radius;
    public:
        circle() {
            cout<<"Construction called for class circle"<<endl;
        }
        void getradius() 
		{
            cout<<"Enter Radius: ";
             cin>>radius; 
        }
        float area() 
		{
            float a = 3.14 * radius * radius;
            return a;
        }
        void print() {
            cout<<"\nRadius: "<<radius<<endl;
            float f = area();
            cout<<"Area of circle is : "<<f<<endl;
        }
        ~circle() {
            cout<<"Destructor called for class circle"<<endl;
        }
};

class cylinder : public circle {
        int height;
    public:
        cylinder() {
            cout<<"Construction called for class cylinder"<<endl;
        }
        void getheight() {
            cout<<"enter the height of cylinder\n";
            cin>>height;
        }        
        float surArea() {
            float a = (2 * 3.14 * radius * (height+radius));
            return a;
        }
        float volume() {
            float v = 3.14 * radius *radius * height;
            return v;
        }
        void print() {
            cout<<"\nHeight of the cylinder is= "<<height<<endl;
            float a = surArea();
            float v = volume();
            cout<<"Surface area of the cylinder is=  "<<a<<endl;
            cout<<"Volume of the cylinder is =  "<<v<<endl;
        }
        ~cylinder() {
            cout<<"\nDestructor called for class cylinder"<<endl;
        }
};

int main() {
    cylinder obj;
    obj.getPoint();
    obj.getradius();
    obj.getheight();
    obj.point :: print();
    obj.circle :: print();    
    obj.print();
    return 0;
}
