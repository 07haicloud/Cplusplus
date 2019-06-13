#include "MyPoint.h"



MyPoint::MyPoint()
{
	
}
MyPoint::MyPoint(int X, int Y) : mPosX(X), mPosY(Y)
{
}

MyPoint::~MyPoint()
{
}

void MyPoint::Display() {
	cout << "Value: x= " << this->mPosX << " y=" << this->mPosY<<endl;
}
int MyPoint::getX() {
	return this->mPosX;
}
int MyPoint::getY() {
	return this->mPosY;
}
void MyPoint::setX(int newX) {
	this->mPosX = newX;
}
void MyPoint::setY(int newY) {
	this->mPosY = newY;
}
double MyPoint::Distance(MyPoint p) {
	double result = 0;
	result = result +  ((p.getX() - this->mPosX) * (p.getX() - this->mPosX));
	result = result + ((p.getY() - this->mPosY) * (p.getY() - this->mPosY));
	result = sqrt(result);
	return result;
}
