#pragma once
#include<iostream>
using namespace std;
class MyPoint
{
private:
	int mPosX;	// X is position
	int mPosY;	// Y is position
public:

	MyPoint();
	MyPoint(int X, int Y);
	void Display();
	int getX();
	int getY();
	void setX(int newX);
	void setY(int newY);
	double Distance(MyPoint p);
	~MyPoint();
};

