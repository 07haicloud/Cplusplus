#include "MyPoint.h"
void main() {
	// Add 2 points for testing 
	MyPoint p1 = MyPoint(1, 1);
	MyPoint p2 = MyPoint(2, 2);

	//Test Display function
	p1.Display();

	// Test getters setters
	cout << "p1: x= " << p1.getX() << " y=" << p1.getY()<<endl;
	p2.setX(3);
	p2.setY(3);
	p2.Display();

	// Test Distance function
	cout<<"Distance between p1 and p2: "<<p1.Distance(p2)<<endl;
	system("pause");
}